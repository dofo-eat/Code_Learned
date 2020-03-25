/*************************************************************************
	> File Name: 13.创建十个子进程-3.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月24日 星期二 19时49分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>

int main() {
    int pid, x = 0;
    for(int i = 1; i <= 10; i++) {
        if((pid == fork()) < 0) {
            perror("fork()");
            continue;
        }
        if(pid == 0) {
            x = i;
            break;
        }
    }
    printf("i am %dth Child.\n", x);
    sleep(60);
    return 0;
}
