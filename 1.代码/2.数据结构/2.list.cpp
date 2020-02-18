/*************************************************************************
	> File Name: 2.list.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月11日 星期二 19时07分50秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct listnode{
    int data;
    struct listnode *next;
}listnode;
//节点的定义
typedef struct list{
    listnode head;
    int length;
}list;
//链表的定义

listnode *getnewnode(int val) {
    listnode *p = (listnode *) malloc(sizeof(listnode));
    p->data = val;//数据域
    p->next = NULL;//指针域
    return p;
}
//节点的初始化

list *getnewlist() {
    list *l = (list *) malloc(sizeof(list));
    l->head.next = NULL;
    l->length = 0;
    return l;
}
//链表的初始化

int insert(list *l, int ind, int val) {
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->length) return 0;
    listnode *p = &(l->head), *node = getnewnode(val);
    while(ind--) p = p->next;//为什么不能用--ind 因为在0的时候会吃县负数， 死循环
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(list *l, int ind) {
    if(l == NULL) return 0;
    if(ind < 0 || ind >= l->length) return 0;
    listnode *p = &(l->head), *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length -= 1;
    return 1;
}

void output(list *l) {
    printf("list(%d) = [", l->length);
    for(listnode *p = l->head.next;p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return ;
}

void rev(list *l) {
    if(l == NULL) return ;
    listnode *p = l->head.next, *q;
    while(p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return ;
}

void clear_listnode(listnode *node) {
    if(node == NULL) return ;
    free(node);
    return ;
} 
//节点的释放
void clear_list(list *l) {
    if(l == NULL) return ;
    listnode *p = &(l->head), *q;
    while(p) {
        q = p->next;
        clear_listnode(p);
        p = q;
    }
}
//链表的回收
int main () {
    #define max_op 20
    int op, ind, val;
    list *l = getnewlist();
    for(int i = 0; i < max_op; i++) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch(op) {
            case 0:
            case 1: {
                printf("insert %d at %d to list = %d\n",val,ind, insert(l, ind, val) );
            }break;
            case 2: {
                printf("erase item at %d from list = %d\n", val, ind, erase(l,ind));
            }break;
            case 3:{
                printf("reverse the list\n");
                rev(l);   
               }break;
        }
        output(l);
        printf("\n");
    }
    clear_list(l);
    return 0;
}
