/*************************************************************************
	> File Name: server.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月04日 星期六 20时28分14秒
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

int main () {
   int shmid;
    key_t key = ftok(".", 198);//得到id
    
    if((shmid = shmget(key, 4096, IPC_CREAT | 0666)) < 0) {
        //共享内存 所有人刻读可写
        perror("shmget");
        return 1;
    }
    
    if((share_memory = shmat(shmid, NULL, 0)) < 0){
        //真实的地址
        perror("shmat");
        return 1;
    }
    while (1) {
        printf("server %s \n",share_memory);
        sleep(2);
    }
    return 0;
} 
