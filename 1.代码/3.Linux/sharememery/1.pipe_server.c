/*************************************************************************
	> File Name: 1.pipe_server.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月07日 星期二 20时19分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    pid_t pid;
    int pipefd[2];
    pipe(pipefd);
    char buff[1024] = {0};
    if((pid = fork()) < 0) {
        perror("fork");
        return 1;
    }
    
    if(pid == 0) {
        while (1) {
            scanf("%[^\n]s",buff);
            getchar();
            write(pipefd[1], buff, strlen(buff));
        }
    }
    else {
        while(1) {
            read(pipefd[0], buff, 1024);
            printf("server :%s\n", buff);
        }
    }
    return 0;
}
