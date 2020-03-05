/*************************************************************************
	> File Name: 约瑟夫环问题.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月05日 星期四 18时14分44秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *circle_create(int n);
void count_off(Node *head, int n, int k, int m);

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    Node *head = circle_create(n);
    count_off(head, n, k, m);
    return 0;
}

Node *circle_create(int n) {
    Node *temp, *new_node, *head;
    int i;

    // 创建第一个链表节点并加数据
    temp = (Node *) malloc(sizeof(Node));
    head = temp;
    head->data = 1;

    // 创建第 2 到第 n 个链表节点并加数据
    for(i = 2; i <= n; i++) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = i;
        temp->next = new_node;
        temp = new_node;
    }

    // 最后一个节点指向头部构成循环链表
    temp->next = head;

    return head;
}

void count_off(Node *head, int n, int k, int m) {
    Node *p1, *p2;
    p2 = head; p1 = p2->next;
    while(p1->next != p2) p1 = p1->next;
    while(p2->data != k) {
        p1 = p1->next;
        p2 = p2->next;
    }
    while(p1 != p2) {
        int i;
        for(int i = 1; i < m; i++) {
            p1 = p1->next;
            p2 = p2->next;
        }
        printf("%d ", p2->data);
        p1->next = p2->next;
        free(p2);
        p2 = p1->next;
    }
    printf("%d\n", p2->data);
    return;
}
