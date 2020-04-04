/*************************************************************************
	> File Name: a.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月04日 星期六 18时20分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <fcntl.h>
#include <sys/file.h>

int main () {
    FILE *f = fopen("./a", "r");
    flock(f->_fileno, LOCK_RX);
    printf("in a :after flock()!\n");
    sleep(10);
    flock(f->_file, LOCK_UN);
    fclose(f);
    return 0;
}
