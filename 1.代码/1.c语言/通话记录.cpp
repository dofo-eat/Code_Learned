/*************************************************************************
	> File Name: 通话记录.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月17日 星期一 12时41分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue {
    long long int *data;
    long long int head, tail, length, count;
}Queue;

Queue *init(int n) {
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->data = (long long *)malloc(sizeof(long long)*n);
    q->head = 0;
    q->tail = -1;
    q->length = n;
    q->count = 0;
    return q;
}

int push(Queue *q, long long int val) {
    if(q->tail >=  q->length) return 0;
    q->tail++;
    if(q->tail >= q->length) q->tail -= q->length;
    q->count++;
    q->data[q->tail] = val;
    return 1;
}

int empty(Queue *q) {
    return q->count == 0;
}

void pop(Queue *q) {
    if(empty(q)) return ;
    q->head++;
    if(q->head >= q->length) q->head -= q->length;
    q->count -= 1;
    return;
}

long long int front(Queue *q) {
    if(empty(q)) return 0;
    return q->data[q->head];
}

void clear(Queue * q) {
    free(q->data);
    free(q);
}

int main () {
    long long int n, num;
    Queue *q1 = init(15);
    Queue *q2 = init(15);
    Queue *q3 = init(15);
    for(int i = 0; i < 10; i++) {
        scanf("%d %lld", &n, &num);
        switch(n) {
            case 0:push(q1, num);
            case 1:push(q2, num);
            case 3:push(q3, num);
        }
    }
    for(int j = 0; j < 10; j++) {
        printf("%lld %lld %lld", front(q1), front(q2), front(q3));
        pop(q1);
        pop(q2);
        pop(q3);
    }
    clear(q1);
    clear(q2);
    clear(q3);
    return 0;
}
