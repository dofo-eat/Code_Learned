/*************************************************************************
	> File Name: 14.fork和exec的使用-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月26日 星期四 18时12分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {
    pid_t pid;
    char filename[512] = {0};
    char name[512] = {0};
    char type[256] = {0}; 
    char cmd[512] = {0};
    if(argc < 2) {
        //有错
        fprintf(stderr, "Usage ：% filename  arg ...\n", argv[0]);
        return 1;
    }
    strcpy(filename, argv[1]);
    char *sub;

    sub = strstr(filename, ".");
    //sub = strrchr (filename, ".")  找最后一个.
    strncpy(name, filename, sub - filename);//指针相减 sub 高地址
    strcpy(type, sub);

    if(!strcmp(type, ".c")) {
        strcpy(cmd, "gcc");    
    } else if(!strcmp(type, ".cpp")) {
        strcpy(cmd, "g++");
    } else {
        fprintf(stderr, "Not support File Type!\n");
    }

    if((pid = fork()) < 0) {
        perror("fork");
        return 3;//资源错误
    }
    if(pid == 0) {
        //子进程
        execlp("vim", "vim", filename, NULL);
    }

    wait(NULL);//vim是否打开
    if((pid = fork()) < 0) {
        perror("fork");
        return 3;
    }
    if(pid == 0) {
        execlp(cmd, cmd, filename,"-o", name, NULL);//gcc filename -o name
    }
    int status;
    wait(&status);
    if(status == 0) {
        printf("OK\n");
        sprintf(name, "./%s", name);
        execlp(name, name, NULL);//./a.out 
    } else {
        printf("Failed\n");
        return 4;
    }
    printf("%d\n", pid);
    return 0;
}
