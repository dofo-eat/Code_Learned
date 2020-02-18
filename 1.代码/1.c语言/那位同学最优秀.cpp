/*************************************************************************
	> File Name: 那位同学最优秀.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月17日 星期一 11时06分42秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList{
    int data;
    struct LinkedList *next;
}Node, *LinkedList;

Node *init(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p; 
}

LinkedList insert(LinkedList head , Node *node, int loc) {
    if(head == NULL ) {
        if(loc != 0) {
            return head;
        }
        head = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while(current_node->next != NULL && count < loc - 1) {
        current_node = current_node->next;
        count++;
    }
    if(count == loc - 1) {
        node->next = current_node->next;
        current_node->next = node;
        return head;
    }
    return head;
}

LinkedList delete_node(LinkedList head, int loc) {
    if(head == NULL) return head;
    Node *current_node = head;
    int count = 0;
    if(index == 0) {
        head = head->next;
        free(current_node);
        return head;
    }
    while(current_node->next != NULL && count < loc - 1) {
        current_node = current_node->next;
        count++;
    }
    if(count == loc - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
        return head;
    }
    return head;
}

int get_val(LinkedList head, int loc) {
    Node *current_node = head;
    for(int i = 0; i < loc; i++) {
        current_node = current_node->next;
    }
    printf("%d\n", current_node->data;)
}

void output(LinkedList head) {
    if(head == NULL) return ;
    Node *current_node = head;
    printf("%d", current_node->data);
    current_node = current_node->next;
    while(current_node != NULL) {
        printf(" %d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    return ;
}

void clear(LinkedList head) {
    Node *current_node = head;
    while(current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main () {
    int n, m, a;
    int length = 0;
    LinkedList l = NULL;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n; i++) {
        Node *node = init(i + 1);
        l = insert(l, node, i);
    }
    for(int j = 0; j < m; j++) {
        scanf("%d", &a);
        Node *node = init(a);
        l = delete_node(l, a - 1);
    }
    int loc = (n - m) / 2;
    get_val(l, loc);
    clear(l);
    return 0;
}
