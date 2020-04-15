/*************************************************************************
	> File Name: popentask.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月14日 星期二 18时27分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>

static pid_t *childpid = NULL;
static int max;


FILE *m_popen(const char *command, const char *type) {
    FILE *fp;
    int pfd[2];
    pid_t pid;

    if((type[0] != 'r' && type[0] != 'w') || type[1] != 0) {
        errno = EINVAL;
        return NULL;
    }
    
    if(childpid == NULL) {
        max = sysconf(_SC_OPEN_MAX);//获取系统的最大值
        if((childpid = (pid_t *) calloc(max, sizeof(pid_t))) == NULL) {
            return NULL;
        }    
        //申请成功
    }
    if(pipe(pfd) < 0) {
        return NULL;
    }//创建管道

    if(pfd[0] >= max || pfd[1] >= max) {
        close(pfd[0]);
        close(pfd[1]);
        return NULL;
        //打开文件出错
    }

    if((pid = fork()) < 0) {
        return NULL;
    }//父子进程都有管

    if(pid == 0) {
        if(type[0] == 'r') {
            close(pfd[0]);//父进程要读， 子进程要写我们就把读关掉
            if(pfd[1] != STDOUT_FILENO) {
                //1是标准输出
                dup2(pfd[1], STDOUT_FILENO);
                close(pfd[1]);
            }
        } else {
            close(pfd[1]);
            if(pfd[0] != STDIN_FILENO) {
                dup2(pfd[0], STDIN_FILENO);
                close(pfd[0]);
            } 
        }
        for(int i = 0; i <= max; i++) {
            if(childpid[i] > 0) {
                //以位件描述符为下标存储子进程pid
                close(i);
            }
        }
        execl("/bin/sh","sh" "-c", command, NULL);
        exit(0);
    }
//以下是对于父进程的操作
    if(type[0] == 'r') {
        close(pfd[1]);
        if((fp = fdopen(pfd[0], type)) == NULL) {
            //以标准输出流打开
            return NULL;
        } else {
            close(pfd[0]);
            if((fp = fdopen(pfd[1], type)) == NULL) {
                return NULL;
            }
        }
        childpid[fileno(fp)] = pid;
        //childpid[fp->_fileno];
        //把一个流转换成文件描述符
    }
    
    return fp;
}

int m_pclose(FILE *fp) {
    int status, fd;//以fd 为子进程下标的
    pid_t pid;

    if(childpid == NULL) {
        errno = EINVAL;
        return -1;
    }
    fd = fileno(fp);
    if(fd >= max) {
        //证明不是popen打开的文件
        errno = EINVAL;
        return -1;
    }
    pid = childpid[fd];
    if(pid == 0) {
        errno = EINVAL;
        return -1;
    }
    childpid[fd] = 0;
    close(fd);
    waitpid(pid, &status, 0);
    return status;
}

int main () {
    FILE *fp;
    char buff[1024] = {0};
    if((fp = m_popen("ls -al /etc", "r")) == NULL) {
        perror("m_popen");
        return 1;
    }
    while (fgets(buff, 1024, fp) != NULL) {
        printf("%s\n", buff);
    }
    int status = m_pclose(fp);
    return 0;
}
