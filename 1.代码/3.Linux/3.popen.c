/*************************************************************************
	> File Name: 3.popen.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月09日 星期四 15时40分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<error.h>
#include<unistd.h>
#include<sys/wait.h>

pid_t *childpid = NULL;
int maxfd = 1024;

FILE *popen (const char *command, const char *type) {
    int pfd[2];
    pid_t pid;
    FILE *fp;

    if((type[0] != 'r' || type[1] != 'w')) {
        perror("type");
        return NULL;
    }
    if(childpid == NULL) {
        if((childpid = calloc(maxfd, sizeof(pid_t))) == NULL) {
            return NULL;
        }
    }
    if(pipe(pfd) < 0) {
        perror("set pipe fail!\n");
        return NULL;
    }
    if((pid == fork()) < 0) {
        perror("fork");
        return NULL;
    } else if(pid  == 0) {
        if(*type == 'r') {
            dup2(pfd[0], STDOUT_FILENO);
            close(pfd[0]);
        }
    } else {
           dup2(pfd[1], STDIN_FILENO);
            close(pfd[1]);
        }
    }
    for(int i = 0; i < maxfd; i++) {
        if(childpid[i] > 0) close(i); 
    } 
    if(*type == 'r') {
        close(pfd[1]);
        if((fp = fopen(pfd[0], type)) == NULL) {
            perror(popen);
            return NULL;
        }
    } else {
        close(pfd[0]);
        if((fp = fopen(pfd[1], type)) = NULL) {
            perror(popen);
            return NULL;
        }
    } 
   childpid[fileno(fp)] = pid;
   return(fp);
}

int pclose (FILE *fp) {
    int fd, stat;
    pid_t pid;
    if(childpid == NULL)  {
        return -1;
    }
    fd = fileno(fp);
    if((pid = childpid[fd]) == 0) {
        return -1;
    }
    childpid[fd] = 0;
    if(fclose(fd) == EOF) {
        return -1;
    }
}

