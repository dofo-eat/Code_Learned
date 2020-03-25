/*************************************************************************
	> File Name: 11.server.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月22日 星期日 20时04分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/wait.h>

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage:%s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen;//端口
    port = atoi(argv[1]);//把字符串转换成整形

    if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        //申请个门
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_listen, (struct sockaddr *)&server, sizeof(server_listen)) < 0) {
        perror("bind");
        exit(1);
    }//传入地址

    if(listen(server_listen, 20) < 0) {
        perror("server");
        exit(1);//判断是否出错
    }
    while(1) {
        int sockfd;
        if((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;//在那里出错
        }
        pid_t pid;
        if((pid = fork()) < 0) {
            perror("fork");
            continue;
        }
        if(pid == 0) {
            close(server_listen);
            char name[20] = {0};
            if(recv(sockfd, name, sizeof(name), 0) <= 0) {
                perror("recv");
                close(sockfd);
            }
            printf("name :%s\n", name);
            exit(0);
        }
        waitpid(-1, NULL, 0);
       /* char name[20] = {0};
        if(recv(sockfd, name, sizeof(name), 0) <= 0) {
            //来之前说明你是谁
            close(sockfd);
            continue;
        }*/
    }
    return 0;
}
