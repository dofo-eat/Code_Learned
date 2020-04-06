/*************************************************************************
	> File Name: 共享内存求和.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月05日 星期日 15时03分44秒
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
 #include<pthread.h>
 #include<sys/wait.h>

struct Shm *share_memory = NULL;

struct Shm {
    int now;
    int sum;
    pthread_mutex_t mutex;//线程锁
};

void do_add(int max, int x) {
    while (1) {
        pthread_mutex_lock(&share_memory->mutex);
        printf("<%d> : %d %d\n", x, share_memory->now, share_memory->sum);
        share_memory->sum += share_memory->now;
        share_memory->now++;
        if(share_memory->now > max) break;
        pthread_mutex_unlock(&share_memory->mutex);
    }
}
int main(int argc, char ** argv) {
    if(argc != 3) {
        fprintf(stderr, "Usage :%s max ins", argv[0]);
        return 1;
    }
    pid_t pid;
    int shmid;
    int max, ins;
    max = atoi(argv[1]);
    ins = atoi(argv[2]);
    key_t key = ftok(".", 198);//得到id
    
    if((shmid = shmget(key, sizeof(struct Shm), IPC_CREAT | 0666)) < 0) {
        //共享内存 所有人刻读可写
        perror("shmget");
        return 1;
    }
    

    if((share_memory = (struct Shm *)hmat(shmid, NULL, 0)) ==  NULL){
        //真实的地址
        perror("shmat");
        return 1;
    }
    memset(share_memory, 0, sizeof(struct Shm));    
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(&share_memory->mutex, &attr);

    int x;    
    
    for(int i = 0; i < ins; i++) {
        if((pid = fork()) < 0 ) {
            perror("fork");
            return 1;
        }
        if(pid == 0) {
            x = i;
            break;
        }
    }
    
    if(pid == 0) {
        do_add(max, x);
        printf("<%d> exit!\n", x);
        exit(0);
    } 
    while (ins) {
        wait(NULL);
        ins--;
    }
    printf("Ans = %d\n", share_memory->sum);
    return 0;
}


