/*************************************************************************
	> File Name: client-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月05日 星期日 13时38分20秒
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
    memset(share_memory, 0, sizeof(struct Shm));
    printf("%d\n", share_memory->pid);
    while (1) {
        printf("client :");
        scanf("%[^\n]s", share_memory->buff);
        getchar();
        if(share_memory->pid == 0) {
            printf("<error> :服务端不再！\n");
        } else {
            kill(share_memory->pid, SIGUSR2);
        }
    }
    return 0;
}
