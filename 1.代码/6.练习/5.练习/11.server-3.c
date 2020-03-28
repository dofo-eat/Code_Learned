/*************************************************************************
	> File Name: 11.server-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月24日 星期二 18时17分58秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include<pthread.h>


void *print(void *arg) {
    printf("%d\n", arg);
}

int main (int argc, char ** argv) {
    void *status;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen;
    port = atoi(argv[1]);

    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    printf("Socket create.\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }
    printf("sockfd bind.\n");
    if (listen(server_listen, 20) < 0) {
        perror("server");
        exit(1);
    }
    
    while (1) {
        int sockfd;
        printf("sockfd before accept.\n");
        int conn = accept(server_listen, (struct sockaddr *)&server, sizeof(server));
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }
        pthread_t tid;
        int pthread_err = pthread_create(&tid, NULL, print,(void*)&conn);
        if(pthread_err != 0) {
            printf("thread failed!\n");
        } else {
            close(server_listen);
            char name[20] = {0};
            if (recv(sockfd, name, sizeof(name), 0) <= 0) {
                perror("recv");
                close(sockfd);
            }
            printf("Name: %s\n", name);
            exit(0);
        }
        printf_join(tid, NULL);
    }
    return 0;
}

/*int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen;
    port = atoi(argv[1]);

    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    printf("Socket create.\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }
    printf("sockfd bind.\n");
    if (listen(server_listen, 20) < 0) {
        perror("server");
        exit(1);
    }
    
    while (1) {
        int sockfd;
        printf("sockfd before accept.\n");
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }

        pid_t pid;
        if ((pid = fork()) < 0) {
            perror("fork");
            continue;
        }
        if (pid == 0) {
            close(server_listen);
            char name[20] = {0};
            if (recv(sockfd, name, sizeof(name), 0) <= 0) {
                perror("recv");
                close(sockfd);
            }
            printf("Name: %s\n", name);
            exit(0);
        }
    }
    return 0;
}
*/
