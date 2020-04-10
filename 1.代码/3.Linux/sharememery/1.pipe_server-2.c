/*************************************************************************
	> File Name: 1.pipe_server-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月09日 星期四 18时47分14秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>



int main() {
    pid_t pid;
    FILE *fp, *fp1;
    int pipefd[2];
    pipe(pipefd);
    char buff[1024] = {0};
    if ((pid = fork()) < 0) {
        perror("fork");
        return 1;
    }
    fp = fdopen(pipefd[1], "w");
    fp1 = fdopen(pipefd[0], "r");
    if (pid == 0) {
        while (1) {
            scanf("%[^\n]s", buff);
            getchar();
            fprintf(fp, "%s\n", buff);
            fflush(fp);
//取消掉全缓冲 
       }
    } else {
        while (1) {
            fscanf(fp1, "%s", buff);
            printf("server : %s\n", buff);
        }
    }
    return 0;
}
