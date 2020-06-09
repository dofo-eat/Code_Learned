/*************************************************************************
	> File Name: server2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月06日 星期六 19时48分34秒
 ************************************************************************/
#include"../common/udp_server.h"
#include"../common/common.h"
#include"../common/head.h"
#include"./game.h"
#include"../common/udp_epoll.h"
#include <unistd.h>

char *conf = "./server.conf";

struct User *rteam;
struct User *bteam;
int data_port;
int port = 0;
//struct Map court;

int main(int argc, char **argv){
    int opt, port = 0, listener, epoll_fd;
    pthread_t draw_t;
    while((opt = getopt(argc, argv, "p;")) != -1){
        switch(opt){
            case 'p':
                port = atoi(optarg);
                break;
            default :
               fprintf(stderr , "Usage: %s [-p port]\n", argv[0]);
                exit(1);
        }
    }
    argc -= (optind - 1);
    argv += (optind - 1);

    if(argc > 1){
        fprintf(stderr , "Usage: %s [-p port]\n", argv[0]);
        exit(1);
    }
    

    if(!port) port = atoi(get_value(conf, "PORT"));
    data_port = atoi(get_value(conf, "DATAPORT"));
    court.width = atoi(get_value(conf, "COLS"));
    court.height = atoi(get_value(conf, "LINES"));
    court.start.x = 1;
    court.start.y = 1;

    rteam = (struct User *)calloc(MAX, sizeof(struct User));
    bteam = (struct User *)calloc(MAX, sizeof(struct User));

    if((listener = socket_create_udp(port)) < 0){
        perror("socket_create_udp");
        exit(1);
    }

    DBG(GREEN"INFO"NONE" : Server start on Prt %d\n",port);

    epoll_fd = epoll_create(MAX * 2);
   
    if(epoll_fd < 0){
           perror("epoll_create");
           exit(1);
    }
    
    struct epoll_event ev, events[MAX * 2];

    ev.events = EPOLLIN;
    ev.data.fd = listener;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listener, &ev);
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    
    while(1){
    
        DBG(YELLOW"EPOLL"NONE" : before epoll_wait\n");
        int nfds = epoll_wait(epoll_fd, events, MAX * 2, -1);
        DBG(YELLOW"EPOLL"NONE" : After epoll_wait\n");

        for(int i = 0; i < nfds; i++){
            char buff[512] = {0};
            DBG(YELLOW"EPOLL"NONE" : Doing with %dth fd\n", i);
            if(events[i].data.fd == listener){
                udp_accept(epoll_fd, listener);
            }else{
                recv(events[i].data.fd, buff, sizeof(buff), 0);
                printf(PINK"RECV"NONE" : %s\n", buff);
            }
        }
    }

    return 0;
}

