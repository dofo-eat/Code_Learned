/*************************************************************************
	> File Name: 3.popen-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月12日 星期日 12时08分40秒
 ************************************************************************/
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include "ourhdr.h"

static pid_t *childpid = NULL;
                       
static int maxfd;

#define SHELL "/bin/sh"

FILE *popen(const char *cmdstring, const char *type) {
    int i, pfd[2];
    pid_t pid;
    FILE *fp;
    if ((type[0] != 'r' && type[0] != 'w') || type[1] != 0) {
        errno = EINVAL;     
        return(NULL);
    }

    if (childpid == NULL) {     
        maxfd = open_max();
        if ( (childpid = calloc(maxfd, sizeof(pid_t))) == NULL)
            return(NULL);
    }

    if (pipe(pfd) < 0)
        return(NULL);   

    if ( (pid = fork()) < 0)
        return(NULL);   
    else if (pid == 0) {
        if (*type == 'r') {
            close(pfd[0]);
            if (pfd[1] != STDOUT_FILENO) {
                dup2(pfd[1], STDOUT_FILENO);
                close(pfd[1]);
            }
        } else {
            close(pfd[1]);
            if (pfd[0] != STDIN_FILENO) {
                dup2(pfd[0], STDIN_FILENO);
                close(pfd[0]);
            }
        }
        for (i = 0; i < maxfd; i++)
            if (childpid[ i ] > 0)
                close(i);

        execl(SHELL, "sh", "-c", cmdstring, (char *) 0);
        _exit(127);
    }
    if (*type == 'r') {
        close(pfd[1]);
        if ( (fp = fdopen(pfd[0], type)) == NULL)
            return(NULL);
    } else {
        close(pfd[0]);
        if ( (fp = fdopen(pfd[1], type)) == NULL)
            return(NULL);
    }
    childpid[fileno(fp)] = pid; 
    return(fp);
}

int pclose(FILE *fp) {

    int fd, stat;
    pid_t pid;

    if (childpid == NULL)
        return(-1);     
    fd = fileno(fp);
    if ( (pid = childpid[fd]) == 0)
        return(-1);     

    childpid[fd] = 0;
    if (fclose(fp) == EOF)
        return(-1);

    while (waitpid(pid, &stat, 0) < 0)
        if (errno != EINTR)
            return(-1); 

    return(stat);   
}

