#include "../common/udp_epoll.h"
#include "../common/head.h"
#include "../common/udp_server.h"
#include "../common/thread_pool.h"
#include "../common/sub.reactor.h"
#include "../common/heart_beat.h"
#include "../game.h"

char *conf = "./server.conf";

//struct Map court;

struct User *rteam;
struct User *bteam;

int repollfd, bepollfd;

int data_port;
//int epoll_fd;
int port = 0;

int main(int argc, char **argv) {
    int opt, listener, epoll_fd;
    //int port = 0;
    pthread_t draw_t, red_t, blue_t, heart_t;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
        case 'p':
            port = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Usage: %s [-p port]\n", argv[0]);
            exit(1);
        }
    }

    argc -= (optind - 1); //个数减少
    argv += (optind  -1); //指针后移
    
    if (argc > 1) {
        fprintf(stderr, "Usage: %s [-p port]\n", argv[0]);
        exit(1);
    }
    
    if (!port) port = atoi(get_value(conf, "PORT")); 
    data_port = atoi(get_value(conf, "DATAPORT"));
    court.width = atoi(get_value(conf, "COLS"));
    court.heigth = atoi(get_value(conf, "LINES"));
    court.start.x = 1;
    court.start.y = 1;

    rteam = (struct User *)calloc(MAX, sizeof(struct User));
    bteam = (struct User *)calloc(MAX, sizeof(struct User));
    
    if ((listener = socket_create_udp(port)) < 0) {
        perror("socket_create_udp");
        exit(1);
    }

    DBG(GREEN"INFO"NONE" : Server start on Port %d\n", port);//DEBUG，-D _D
    
    //pthread_create(&draw_t, NULL, draw, NULL);//Draw interface
    
    epoll_fd = epoll_create(MAX * 2);
    repollfd = epoll_create(MAX);
    bepollfd = epoll_create(MAX);


    if (epoll_fd < 0 || repollfd < 0 || bepollfd < 0) {
        perror("epoll_creat");
        exit(1);
    }

    struct task_queue redQueue;
    struct task_queue blueQueue;

    task_queue_init(&redQueue, MAX, repollfd);
    task_queue_init(&blueQueue, MAX, bepollfd);

    pthread_create(&red_t, NULL, sub_reactor, (void *)&redQueue);
    pthread_create(&blue_t, NULL, sub_reactor, (void *)&blueQueue);
    pthread_create(&heart_t, NULL, heart_beat, NULL);

    struct epoll_event ev, events[MAX * 2]; 
    
    ev.events = EPOLLIN; 
    ev.data.fd = listener;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listener, &ev);
    
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    
    while (1) {
        //w_gotoxy_puts(Message, 1, 1, "waiting for login");
        DBG(YELLOW"Main Thread"NONE" : before epoll_wait\n");
        int nfds = epoll_wait(epoll_fd, events, MAX * 2, -1); 
        DBG(YELLOW"Main Thread"NONE" : After epoll_wait\n");
        
        for (int i = 0; i < nfds; i++) {
            struct User user;
            char buff[512] = {0};
            DBG(YELLOW"EPOLL"NONE" : Doing with %dth fd\n", i);
            if (events[i].data.fd == listener) {
                //accept();
                int new_fd = udp_accept(epoll_fd, listener, &user);
                if (new_fd > 0) {
                    DBG(YELLOW"Main Thread"NONE" :Add %s to %s sub_reactor.\n", user.name, (user.team ? "BLUE" : "RED"));
                    add_to_sub_reactor(&user);
                }
            } else {
                recv(events[i].data.fd, buff, sizeof(buff), 0);
                printf(PINK"RECV"NONE" : %s\n", buff);
            }
            //char info[1024] = {0};
            //recvfrom(events[i].data.fd, (void *)info, sizeof(info), 0, (struct sockaddr *)&client, &len);
            
        }

    }
    return 0;
}
