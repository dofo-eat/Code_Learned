/*************************************************************************
	> File Name: 16.多线程实现server.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月28日 星期六 15时13分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include "head.h"
#include"tcp_server.h"

void chstr(char *str) {
    //把字符串全部大写
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}


void *work(void *arg) {
    int *fd = (int *) arg;
    if(send(fd, "you are here", sizeof("you are here"), 0) < 0) {
        perror("send");
        close(fd);
        return NULL;
    }
    while(1) {
        char msg[512] = {0};
        if(recv:)
    }
}

int main() {
    
    return 0;
}
