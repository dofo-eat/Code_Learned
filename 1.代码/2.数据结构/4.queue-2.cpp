/*************************************************************************
	> File Name: 4.queue-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月13日 星期四 19时46分09秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct Queue {
    int *data;
    int head, tail, size, cnt;

}Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc (sizeof(Queue));
    q->data = (int *)malloc(sizeof (int) * n);
    q->head = q->tail = q->cnt = 0;
    q->size = n;
    return q;
}

int empty(Queue *q) {//传入一个队列
    return !q->cnt;
}

int front(Queue *q) {
    return q->data[q->head];
}

int push(Queue *q, int val) {
    if(q == NULL) return 0;
    if(q->cnt == q->size) return 0;//满了
    q->data[q->tail] = val;
    q->tail += 1;
    q->cnt += 1;
    //q->data[q->tail++] = val;
    return 1;
    
}

int pop(Queue *q) {
    if(q == NULL) return 0;
    if(empty(q)) return 0;//当前队列为空i
    q->head += 1;
    if(q->head == q->size) q->head -= q->size;
    q->cnt -= 1;
    return 1;

}

void output(Queue *q) {
    printf("Queue(%d) = [", q->cnt);
    for(int i = q->head, j = 0; j < q->cnt; j++) {
        j && printf(", ");
        printf("%d", q->data[i + j %(q->size)]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *q) {
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;

}

int main () {
    srand(time(0));
    #define max_op 20 
    Queue *q = init(max_op);
    int op, val;
    for(int i = 0; i <2 * max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to Queue = %d\n", val, push(q, val));                
            }break;
            case 3: {
                printf("pop %d from Queue = %d\n", front(q), pop(q));                
            }break;           
        }
        output(q);
        printf("\n");            
    }
    clear(q);
    return 0;
}
