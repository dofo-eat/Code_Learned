/*************************************************************************
	> File Name: server.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月07日 星期二 18时20分06秒
 ************************************************************************/
 #include "../common/color.h"
 #include "../common/common.h"
 #include "../common/tcp_server.h"
 #include "./common/head.h"

#define MAXTASK 100 //最大任务数
#define MAXTHREAD 20
char ch_char(char c) {
    if(c >= 'a' && c <= 'z') return c - 32;
    return c;
}//转换字符

void do_echo(int fd) {
    char buf[512] = {0};//收信息
    char ch;
    int ind = 0;
    while (1) {
        if(recv(fd, &ch, 1, 0) <= 0 ) {
            break;
        }
        if(ind < sizeof(buf)) {
            buf[ind++] = ch_char(ch);
        }
        if(ch == '\n') {
            send(fd, buf, ind, 0);
            ind = 0;
        }
    }
}

typedef struct {
    int sum;//任务总数
    int *fd;//已有的连接
    int head;
    int tail;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}TaskQueue;

void TaskQueueInit(TaskQueue *queue, int sum) {
    queue->sum = sum;
    queue->fd = calloc(sum, sizeof(int));//存储fd
    queue->head = queue->tail = 0;
    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
}//初始化

void TaskQueuePush(TaskQueue *queue, int fd) {
    pthread_mutex_lock(&queue->mutex);
    queue->fd[queue->tail] = fd;//放入对列的尾部
    if(++queue->tail == queue->sum) {
        queue->tail = 0;
    }
    pthread_cond_signal(&queue->cond);//发送信号
    pthread_mutex_unlock(&queue->mutex);
}

int TaskQueuePop(TaskQueue *queue) {
    pthread_mutex_lock(&queue->mutex);
    while(queue->tail == queue->head) {
        //空对列等信号
        pthread_cond_wait(&queue->cond, &queue->mutex);
    }
    int fd = queue->fd[queue->head];
    if(++queue->head == queue->sum) 
        queue->head = 0;//循环对列
    pthread_mutex_unlock(&queue->mutex);
    return fd;
}

void *thread_run(void *arg) {
    pthread_t tid = pthread_self();
    //获取线程id
    pthread_detach(tid);//不需要等待直接分离
    TaskQueue *queue = (TaskQueue *) arg;
    while (1) {
        int fd = TaskQueuePop(queue);
        do_echo(fd);
    }
}
//对于线程的操作
 int main (int argc, char **argv) {
     if(argc != 2) {
         fprintf(stderr, "Usage :%s port!\n", argv[0]);
         exit(1);
     }
     int port, server_listen, fd;
     port = atoi(argv[1]);

     if((server_listen = socket_create(port)) < 0) {
         perror("socket_create");
         exit(1);
     }
    TaskQueue queue;
    TaskQueueInit(&queue, MAXTASK);

    pthread_t *tid = calloc(MAXTHREAD, sizeof(pthread_t));
    
     for(int i = 0; i < MAXTHREAD; i++) {
         pthread_create(&tid[i], NULL, thread_run, (void *)&queue);
        //给每一个线程分配任务
     }
     
     while(1) {
         if((fd = accept(server_listen, NULL, NULL)) < 0) {
             perror("accept");
             exit(1);
         }
         TaskQueuePush(fd);
         //将任务放到线程池
     }
     return 0;
 }
