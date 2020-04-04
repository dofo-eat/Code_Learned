/*************************************************************************
	> File Name: 文件枷锁求和.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月04日 星期六 15时05分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

void Nsum {

}

int main() {
    int num, n;
    int sum = 0;
    scanf("%d %d", &num, &n);

    pid_t pid;
    for(int i = 0; i < n; i++) {
        pid = fork();
        if(pid == 0 || pid == -1) break;
    }
    if(pid == -1) {
        printf("false\n");
    } else if(pid == 0){
        printf("子进程id: %d", getpid());
    }
    return 0;
}
