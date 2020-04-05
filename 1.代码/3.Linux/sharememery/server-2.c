/*************************************************************************
	> File Name: server-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月05日 星期日 13时48分17秒
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>

struct Shm {
    pid_t pid;
    char buff[1024];
};

struct Shm *share_memory = NULL;

void print() {
    printf("<server> :%s\n", share_memory->buff);
}

int main() {
    int shmid;
    key_t key = ftok(".", 198);
    
    if((shmid = shmget(key, 4096, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return 1;
    }
    if((share_memory =(struct Shm *) shmat(shmid, NULL, 0)) ==  NULL ) {
        perror("shmat");
        return 2;
    }
    printf("after shmat!\n");
    share_memory->pid = getpid();
    while (1) {
        signal(SIGUSR2, print);
    }
    return 0;
}
