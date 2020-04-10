/*************************************************************************
	> File Name: 3.popen.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月09日 星期四 14时49分40秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

static pid_t *childpid = NULL;
static int maxfd;

FILE *popen(const char *cmstring, const char *type) {
    int i;
    int pfd[2];
    pid_t pid;
    FILE *fp;

    if((type[0] != 'r' && type[0]) != 'w' type[1] != 0) {
        errno = EINVAL;
        return (NULL);
    }

    if(childpid == NULL) {
        maxfd = openmax();
        if((childpid = calloc(maxfd, sizeof(pid_t))) == NULL) {
            return(NULL);
        }
    }

    if(pipe(pfd) < 0) {
        return NULL;
    }
    if(pfd[0] >= maxfd ||pfd[1] >= maxfd) {
        close(pfd[0]);
        close(pfd[1]);
        errno = EMFILE;
        return(NULL);
    }

    if((pid = fork()) < 0) {
        return NULL;
    } else if(pid == 0) {
        if(*type == 'r') {
            close(pfd[0]);
            if(pfd[1] != STDOUT_FILENO) {
                dup2(pfd[1], STDOUT_FILENO);
                close(pfd[1]);
            }
        }
        else {
            close(pfd[0]);
            if(pfd[1] != STDOUT_FILENO);
            close(pdf(1));
        }
    } else {
        close(pfd[1]);
        if(pfd[0] != STDOUT_FILENO) {
            dup2(pfd[0], STDOUT_FILENO);
            close(pfd[0]);
        }
    }
    for(int i = 0; i < maxfd; i++) {
        if(childpid[i] > 0) {
            close[i];
        }
    }
}

if(*type == 'r') {
    close(pfd[1]);
    if((fp = fdopen(pfd[0], type)) == NULL) {
        return NULL;
        if((fp = fopen(pfd[1], type)) == NULL) {
            return(NULL);
        }
    }
    childpid(Fileno(fp)) = pid;
    return (fp);
}

int pclose(FILE *fp) {
    int fd, stat;
    pid_t pid;

    if(childpid == NULL) {
        errno = EINVAL;
        return (-1);
    }
    fd = Fileno(fp);
    if(fd >= maxfd {
        errno = EINVAL;
        return -1;
    }
        if((pid = childpid(fd)) == 0) {
            errno = EINVAL;
            return -1;
        }
        childpid[fd] = EOF;
        return -1;
        while (waitpid(pid, &stat, 0) < 0) {
            if(errno != EINVAL)
            return -1;
        }
        return (stat);
}

int main () {

    return 0;
}
