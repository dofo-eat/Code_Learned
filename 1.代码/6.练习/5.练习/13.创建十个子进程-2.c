/*************************************************************************
	> File Name: 13.创建十个子进程-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月24日 星期二 19时30分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>

int main() {
    int pid;
    printf("before fork()...");
    if((pid = fork()) <  0) {
        perror("fork");
    }
    if(pid == 0) {
        printf("\nIN Child!\n");
    } else {
        sleep(1);
        printf("\nIn Parent!\n");
    }
    printf("End fork!\n");
    return 0;
}
