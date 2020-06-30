/*************************************************************************
	> File Name: thread_pool.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 18时14分01秒
 ************************************************************************/
#include "thread_pool.h"
#include "udp_epoll.h"
#include "game.h"

extern int repollfd, bepollfd;

void do_echo(struct User *user) {
    struct FootBallMsg msg;
    char tmp[512] = {0};
    memset(&msg, 0, sizeof(msg));//清空
    int size = recv(user->fd, (void *)&msg, sizeof(msg), 0);
    user->flag = 10;
    if (msg.type & FT_ACK) {
        //说明收到的是ACK包，就应输出心跳信息
        if (user->team)
            DBG(L_BLUE" %s "NONE"心跳❤ \n", user->name);
        else 
            DBG(L_RED" %s "NONE"心跳❤ \n", user->name);
    } else if (msg.type & (FT_WALL | FT_MSG)) {
        //收到的是广播或者信息需要回响
        if (user->team)
            DBG(L_BLUE" %s : %s\n"NONE, user->name, msg.msg);
        else 
            DBG(L_RED" %s : %s\n"NONE, user->name, msg.msg);
        strcpy(msg.name, user->name);
        msg.team = user->team;
        Show_Message(, user, msg.msg, );
        send(user->fd, (void *)&msg, sizeof(msg), 0);//回响 
    } else if (msg.type & FT_FIN) {
        //客户端要关闭连接
        DBG(RED"%s log out.\n",user->name);
        sprintf(tmp, "%s Logout.", user->name);
        Show_Message(, NULL, tmp, 1);//显示用户退出信息
        user->online = 0;//修改退出用户的信息
        int epollfd_tmp = (user->team  ? bepollfd : repollfd);
        del_event(epollfd_tmp, user->fd);
        //删除掉要退出的客户端
    } else if (msg.type = FT_CTL) {//控制信息
        Show_Message(, user, "Ctrl Message", 0);
        if (msg.ctl.dirx || msg.ctl.diry) {
            //位置有变化才更新
            user->loc.x += msg.ctl.dirx;
            user->loc.y += msg.ctl.diry;
            //以下用来判断边界
            if (user->loc.x <= 1) user->loc.x = 1;
            if (user->loc.x >= court.width - 1) user->loc.x = court.width - 1; 
            if (user->loc.y <= 1) user->loc.y = 1;
            if (user->loc.y >= court.height - 1) user->loc.y = court.height - 1;
        } 
    } 
} 

void task_queue_init(struct task_queue *taskQueue, int sum, int epollfd) {
    taskQueue->sum = sum;
    taskQueue->epollfd = epollfd;
    taskQueue->team = calloc(sum, sizeof(void *));//存放指针
    taskQueue->head = taskQueue->tail = 0;
    pthread_mutex_init(&taskQueue->mutex, NULL);
    pthread_cond_init(&taskQueue->cond, NULL);
}

void task_queue_push(struct task_queue *taskQueue, struct User *user) {
    pthread_mutex_lock(&taskQueue->mutex);
    taskQueue->team[taskQueue->tail] = user;//在最后添加元素
    DBG(L_GREEN"Thread Poll : "NONE"Tash Push %s\n", user->name);
    if (++taskQueue->tail == taskQueue->sum) {
        DBG(L_GREEN"Thread poll : "NONE"Task Queue End.\n");
        taskQueue->tail = 0;
    }
    pthread_cond_signal(&taskQueue->cond);
    //发一个信号告诉线程有新任务来了
    pthread_mutex_unlock(&taskQueue->mutex);
}

struct User *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    while (taskQueue->tail == taskQueue->head) {
        DBG(L_GREEN"Thread poll : "NONE"Task Queue Empty, watting for task.\n");
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex); 
    }
    struct User *user = taskQueue->team[taskQueue->head];//取到待弹出元素的
    DBG(L_GREEN"Thread poll : "NONE"Task Pop %s.\n", user->name);
    if (++taskQueue->head == taskQueue->sum) {
        DBG(L_GREEN"Thread poll : "NONE"Task Queue End.\n");
        taskQueue->head = 0;
    }
    pthread_mutex_unlock(&taskQueue->mutex);
    return user;
}

void *thread_run(void *arg) {
    pthread_t tid = pthread_self();
    pthread_detach(tid);//线程分离
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        struct User *user = task_queue_pop(taskQueue);
        do_echo(user);
    }
}
