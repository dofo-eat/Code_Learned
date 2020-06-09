/*************************************************************************
	> File Name: threadpool.h
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月07日 星期日 18时53分45秒
 ************************************************************************/

#ifndef _THREADPOOL_H
#define _THREADPOOL_H

typedef struct threadpool {
    task_t *first;
    task_t *last;
    int counter;
}threadpool_t;

#endif
