/*************************************************************************
	> File Name: 4.cp-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月22日 星期日 15时54分54秒
 ************************************************************************/
/*************************************************************************
    > File Name: cp.c
    > Author: zhangfengbo
    > Mail:1819067326@qq.com 
    > Created Time: 2020年03月22日 星期日 15时43分47秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 512


int main(int argc, char **argv) {
    int fd_in, fd_out;
    ssize_t nread;
    char buf[BUFSIZE + 5] = {0};

    if (argc != 3) {
        printf("Usage: %s sourcefile destfile\n", argv[0]);
        exit(1);
    }

    if ((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }

    if ((fd_out = creat(argv[2], 0644)) == -1) {
        perror(argv[2]);
        exit(1);
    }

    while ((nread = read(fd_in, buf, BUFSIZE)) > 0) {
        printf("nread = %ld\n", nread);
        int nwrite;
        if ((nwrite = write(fd_out, buf, nread)) != nread) {
            perror("write");
        }
        memset(buf, 0, BUFSIZE + 5);
        printf("nwrite = %d\n", nwrite);
    }

    close(fd_in);
    close(fd_out);
    return 0;
}

