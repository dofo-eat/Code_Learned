/*************************************************************************
	> File Name: client.c
	> Author: suyelu
	> Mail: suyelu@haizeix.com
	> Created Time: 日  3/22 20:21:53 2020
 ************************************************************************/

#include  "head.h"
#include  "common.h"
int socket_connect(char *host, int port) {
    int sockfd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    printf("Socket create.\n");
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return -1;
    }
    return sockfd;
}


int socket_connect_timeout(char *host, int port, long timeout) {
    int sockfd, retval;
    fd_set wfds;
    struct timeval tv;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    make_nonblock(sockfd);
    FD_ZERO(&wfds);
    FD_SET(sockfd, &wfds);
    tv.tv_sec = 0;
    tv.tv_usec = timeout;

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        int error = -1;
        retval = select(sockfd + 1, NULL, &wfds, NULL, &tv);
        int len = sizeof(int);
        if(retval < 0){
            close(sockfd);
            return -1;
        }else if(retval){
            if(getsockopt(sockfd, SOL_SOCKET,SO_ERROR, &error, (socklen_t *)&len) < 0){
                close(sockfd);
                return -1;
            }
            if(error){
                close(sockfd);
                return -1;
            }
        }else{
            printf("Connect Time Out!\n");
            close(sockfd);
            return -1;
        }
    }
    make_block(sockfd);
    return sockfd;
}
