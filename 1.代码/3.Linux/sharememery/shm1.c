/*************************************************************************
	> File Name: shm1.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月04日 星期六 19时09分07秒
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

void print(int sig) {
    printf("<parent> :%s\n",share_memory);
}

int main() {
    pid_t pid;
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

    if((pid = fork()) < 0) {
        perror("forki");
        return 1;
    }

    if(pid == 0) {
        while(1) {
            sleep(1);
            printf("<chrld> :");
            scanf("%[^\n]s", share_memory);
            getchar();
            kill(getppid(), SIGUSR2);
        }
    } else {
        while(1) {
         /*   printf("<parent> :%s\n", share_memory);
            sleep(5);*/
            signal(SIGUSR2, print);
        }
    }
    return 0;
}
