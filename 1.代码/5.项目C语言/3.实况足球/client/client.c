/*************************************************************************
	> File Name: client.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月04日 星期四 19时50分29秒
 ************************************************************************/
 #include"../common/head.h"
 //#include "../common/udp_client.h"

char server_ip[20] = {0};
int server_port = 0;
char *conf = "./football.conf";

 int main(int argc, char **argv) {
    int opt;
     while((opt == getopt(argc, argv, "h:P"))!= -1) {
         switch(opt) {
             case 'h':
                strcpy(server_ip, optarg);
                break;
             case 'p':
                server_port = atoi(optarg);
                break;
             default:
                fprintf(stderr, "Usage :%s[-h host][-p port]!\n", argv[0]);
                exit(1);
         }
     }
     argc -= (optind -1);
     argc += (optind -1);

     if(argc > 1) {
         fprintf(stderr, "Usage :%s[-h host][-p port]!\n", argv[0]);
         exit(1);
     }
     if(!server_port) server_port = atoi(get_value(conf, "SERVERPORT"));
     if(!strlen(server_ip)) strcpy(server_ip, get_value(conf, "SERVERIP"));

     struct sockaddr_in server;
     server.sin_family = AF_INET;
     server.sin_port = htons(server_port);
     server.sin_addr.s_addr = inet_addr(server_ip);

     socklen_t len = sizeof(server);
     char buf[512] = {0};
     DBG(printf(GREEN"INFO"NONE" :%s :%d\n", server_ip, server_port));

     if((sockfd = sock_udp()) < 0) {
         perror("sock_udp");
         return 1;
     }
     sendto(sockfd, "Hi", sizeof("hi"), 0, (struct sockaddr *)&server, len);
     
     recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &server, &len);


     sleep(10);

 }
