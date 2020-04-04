/*************************************************************************
	> File Name: client.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月04日 星期六 20时01分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<signal.h>

char *share_memory = NULL;

int main() {
    int shmid;
    key_t key = ftok(".", 198);
    
    if((shmid = shmget(key, 4096, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return 1;
    }
    if((share_memory = shmat(shmid, NULL, 0)) < 0 ) {
        perror("shmat");
        return 2;
    }
    while (1) {
        sleep(1);
        printf("client :");
        scanf("%[^\n]s", share_memory);
        getchar();
    }
    return 0;
}
