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
#include<pthread.h>
#include<sys/wait.h>

struct Shm {
    //pid_t pid;
    char buff[1024];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

struct Shm *share_memory = NULL;

/*void print() {
    printf("<server> :%s\n", share_memory->buff);
}*/

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
    memset(share_memory, 0, sizeof(struct Shm));
    
    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;
    
    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);

    pthread_mutexattr_setpshared(&m_attr, PTHREAD_PROCESS_SHARED);
    pthread_condattr_setpshared(&c_attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(&share_memory->mutex, &m_attr);
    pthread_cond_init(&share_memory->cond, &c_attr);

    while (1) {
        pthread_mutex_lock(&share_memory->mutex);
        pthread_cond_wait(&share_memory->cond, &share_memory->mutex);
        printf("<Recv :%s\n", share_memory->buff);
        pthread_mutex_unlock(&share_memory->mutex);
    }
    return 0;
}
