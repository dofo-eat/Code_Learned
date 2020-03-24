/*************************************************************************
	> File Name: 12.client.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月22日 星期日 20时22分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    int sockfd, port;
    struct sockaddr_in server;
    if(argc != 3) {
        fprintf(stderr, "Usage:%s ip port\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[2]);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    printf("Socket create.\n");
    if(connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }
    if(send(sockfd, "suxx", sizeof("suxx"), 0) < 0) {
        perror("send");
        exit(1);
    }
    close(sockfd);
    return 0;
}
