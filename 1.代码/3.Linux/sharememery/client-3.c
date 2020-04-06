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
#include<sys/wait.h>
#include<pthread.h>

struct Shm {
    //pid_t pid;
    char buff[1024];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
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
    /*memset(share_memory, 0, sizeof(struct Shm));
    pthread_mutexattr_t attr;
    pthread_mutexattr_init (&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(&share_memory->mutex, &attr);

    printf("%d\n", share_memory->pid);*/

    while (1) {
        printf("Before mutex lock!\n");
        pthread_mutex_lock(&share_memory->mutex);
        printf("After mutex lock!\n");
        printf("client :");
        scanf("%[^\n]s", share_memory->buff);
        getchar();
        pthread_cond_signal(&share_memory->cond);
        sleep(1);
        pthread_mutex_unlock(&share_memory->mutex);
       /* if(share_memory->pid == 0) {
            printf("<error> :服务端不再！\n");
        } else {
            kill(share_memory->pid, SIGUSR2);
        }*/
    }
    return 0;
}
