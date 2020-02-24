/*************************************************************************
	> File Name: 但链表的就地转制.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月18日 星期二 20时13分18秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if(head == NULL) {
        if(index != 0) {
            return head;
        }
        head = node;
        return head;
    }
    if(index == 0) {
        node->next = head;
        head = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while(current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if(count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
        return head;
    }
    return head;
}

void output(LinkedList head) {
    if(head == NULL) return ;
    Node *current_node = head;
    while(current_node != NULL) {
        printf("%c ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

LinkedList reverse(LinkedList head) {
    if(head == NULL) {
        return head;
    }
    Node *next_node, *current_node;
    current_node = head->next;
    head->next = NULL;
    while(current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

int main () {
    LinkedList linkedlist = NULL;
    int m;
    char t;
    scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%c", &t);
            Node *node = (Node *)malloc(sizeof(Node));
            node->data = t;
            node->next = NULL;
        linkedlist = insert(linkedlist, node, i);
    }
    linkedlist = reverse(linkedlist);
    output(linkedlist);
    return 0;
}
