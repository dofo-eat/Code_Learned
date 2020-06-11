/*************************************************************************
	> File Name: server.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月04日 星期四 15时22分53秒
 ************************************************************************/
#include "../common/common.h"
#include "../common/udp_server.h"
#include "../common/color.h"
#include "../common/head.h"
#include <unistd.h>
#include "./game.h"

char *conf = "./server.conf";

struct User *rteam;//存放两个队的用户端
struct User *bteam;
int data_port;

int main(int argc, char **argv) {
    int opt, port = 0, listener;
    pthread_t draw_t;
    /*while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p'://指定端口
                port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-p port]\n", argv[0]);
                exit(1);
        }
    }
    argc -= (optind - 1);//选项个数减一
    argv += (optind - 1);
*/
    if (argc > 1) {
        fprintf(stderr, "Usage: %s [-p port]\n", argv[0]);
        exit(1);
    }

    if (!port) port = atoi(get_value(conf, "PORT"));
    data_port = atoi(get_value(conf, "DATAPORT"));
    court.width = atoi(get_value(conf, "COLS"));
    court.height = atoi(get_value(conf, "LINES"));
    court.start.x = 1;
    court.start.y = 1;
    //分配存储空间
    rteam = (struct User *)calloc(MAX, sizeof(struct User));
    bteam = (struct User *)calloc(MAX, sizeof(struct User));
    
    if ((listener = socket_create_udp(port)) < 0) {
        perror("socket_create_udp");
        exit(1);
    }
   
    DBG(GREEN"INFO"NONE" : Server start on Port %d\n", port);
    
    pthread_create(&draw_t, NULL, draw, NULL);//用来绘制界面
    while(1) {
        w_gotoxy_puts(Message, 1, 1, "111111111");
        struct LogData lg;
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        recvfrom(listener, (void *)&lg, sizeof(lg), 0,(struct sockaddr *) &client, &len);
        char info[1024];
        sprintf(info, "Login : %s :%d", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        w_gotoxy_puts(Message, 1, 2, info);
    }
    return 0;
}

