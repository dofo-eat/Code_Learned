/*************************************************************************
	> File Name: 13.创建十个子进程.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月24日 星期二 18时58分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>

int main(int argc, char **argv) {
    int pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9, pid10;
    if((pid1 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid2 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid3 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid4 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid5 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid6 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid7 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid8 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid9 = fork()) == 0) sleep (60);
    exit(-1);
    if((pid10 = fork()) == 0) sleep (60);
    exit(-1);
    return 0;
}
