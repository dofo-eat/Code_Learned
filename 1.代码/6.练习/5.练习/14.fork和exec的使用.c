/*************************************************************************
	> File Name: 14.fork和exec的使用.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月26日 星期四 15时19分59秒
 ************************************************************************/ 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    pid_t pid;
    char filename[512] = {0};
    char name[512] = {0};
    char tmp[5] = {0};
    char cc_flag[50] = {0};

    if (argc != 2) {
        printf("Usage: ./a.out codefile\n");
        exit(1);
    }
    strcpy(filename, argv[1]);

    char *sub;

    sub = strstr(filename, ".");
    strncpy(name, filename, sub - filename);
    strcpy(tmp, sub);

    printf("%s\n", tmp);
    if (!strcmp(tmp, ".c")) {
        strcpy(cc_flag, "gcc");
    } else if (!strcmp(tmp, ".cpp")) {
        strcpy(cc_flag, "g++");
    } else {
        printf("Not Support File Type\n");
        exit(2);
    }

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(3);
    }

    if (pid == 0) {
        execlp("/usr/bin/vim", "vim", filename, NULL);
    }
    wait(NULL);
    return 0;
}
