/*************************************************************************
	> File Name: sub_reactor.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 23时19分09秒
 ************************************************************************/

#include"sub_reactor.h"
#include"head.h"
#include"thread_pool.h"

#define MAX 50

void *sub_reactor(void *arg){
    struct task_queue *taskQueue = (struct task_queue *)arg;
    pthread_t *tid = (pthread_t *)calloc(MAXTHREAD, sizeof(pthread_t));
    for(int i = 0; i < MAXTHREAD; i++){
        pthread_create(&tid[i], NULL, thread_run, (void *)taskQueue);
    }
    struct epoll_event ev, events[MAX];
    int nfds;
    while(1){
        DBG(RED "Sud Reactor : " NONE "Epoll weiting...\n");
        nfds = epoll_wait(taskQueue->epollfd, events, MAX, -1);
        if(nfds == -1){
            perror("epoll_wait");
            exit(1);
        }
        for(int i = 0; i < nfds; ++i){
            struct User *user = (struct User *)events[i].data.ptr;
            DBG(YELLOW "events[%d].data.ptr->name = %s : " NONE "\n",i, user->name);
            if(events[i].events & EPOLLIN){//有数据可读
                task_queue_push(taskQueue, user);
            }
        }
    }

    return NULL;
}

