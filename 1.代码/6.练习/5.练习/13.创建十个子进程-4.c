/*************************************************************************
	> File Name: 13.创建十个子进程-4.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月24日 星期二 20时02分30秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int pid, x;
    for (int i = 1; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            continue;
        }
        if (pid == 0) {//
            x = i;
            break;
        }
    }
    printf("I'm %dth Child.\n", x);
    sleep(60);
    return 0;
} 
