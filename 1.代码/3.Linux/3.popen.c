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

char buff[1024] = {0};

int main(int argc, char **argv) {
    /*if(argc != 3) {
        perror(stderr, "Usage %s \n", argv[0]);
        return 1;
    }*/
    FILE *popen (const char *command, const char *type) {
        int pfd[2];
        pid_t pid;
        FILE *fp;

        if((type[0] != 'r' || type[1] != 'w')) {
            perror("type");
            return NULL;
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
                dup2(pfd[0], buff);
                close(pfd[0]);
            }
        } else {
               dup2(pfd[1], buff);
                close(pfd[1]);
            }
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
        return fp;
    }

    return 0;
}
