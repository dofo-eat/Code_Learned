/*************************************************************************
	> File Name: server.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月02日 星期二 18时14分48秒
 ************************************************************************/
 #include "../common/color.h"
 #include "../common/udp_server.h"
 #include "../common/common.h"
 #include "../common/head.h"
 #include "./game.h"
 char *conf = ",/server.conf";

struct User *rteam;
struct User *bteam;

struct data

struct Map court;

int main(int argc, char**argv) {
    int opt, port =0,listener;
    pthread_t draw_t;
    while((opt = getopt(argc, argv, "p:")) != -1) {
        switch(opt) {
            case 'p':
                port=atoi(optarg);
                break;
            default:
            fprintf(stderr, "Usage : %s[-p port]\n", argv[0]);
            exit(1);
        }
    }
    argc -= (optind - 1);
    argv += (optind - 1);
    if(argc > 1) {
        fprintf(stderr, "Usage:%s[-p port]\n", argv[0]);
        exit(1);
    }
    if(!port) {
        port = atoi(get_value(conf, "port"));
    }
    court.width = atoi(get_value(conf, "COLS"));
    court.heigth = atoi(get_value(conf, "LINES"));
    court.start.x = 1;
    court.start.y = 1;

    rteam = (struct User *) calloc(MAX, sizeof(struct User));
    bteam = (struct User *) calloc(MAX, sizeof(struct User));

    if((listener = socket_create_udp(port)) < 0) {
        perror("socket_create_udp");
        exit(1);
    }

    

    DBG(GREEN"INFO"NONE":server start on port %d\n", port);   
    pthread_create(&draw_t, NULL, draw, NULL);
    while(1) {
        w_gotoxy_puts(Message, 1, 1, "123989002304");
        struct LogData lg;
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        recvfrom(listener, (void *)&lg, sizeof(lg), 0, (struct sockaddr *)&client, &len);
        char info[1024];
        sprintf(info,"Login:%s : %d", inet_ntoa(client, sin_addr), ntohs(client.sin_port));
    }
    return 0;
}
