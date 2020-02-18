/*************************************************************************
	> File Name: 神奇的二叉树.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月17日 星期一 15时36分49秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data;
    struct Node *lchild, *rchild;
}Node;

Node *init(char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = node->rchild =  NULL;
    return node;
}

Node *build(char *pre_str, char *in_str, int len) {
    Node *p = init(pre_str[0]);
    int pos = strchr(in_str, pre_str[0]) -in_str;
    if(pos > 0) {
        p->lchild = build(pre_str + 1, in_str, pos);
    }
    if(len - pos - 1 > 0) {
        p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    }
    return p;
}

void post_order(Node *node) {
    if(node->lchild) {
        post_order(node->lchild);
    }
    if(node->rchild) {
        post_order(node->rchild);
    }
    printf("%c", node->data);
}

void post_order1(Node *node) {
    if(node->rchild) {
        post_order1(node->rchild);
    }
    if(node->lchild) {
        post_order1(node->lchild);
    }
    printf("%c", node->data);
}

void clear(Node *node) {
    if(node->lchild) {
        clear(node->lchild);
    }
    if(node->rchild) {
        clear(node->rchild);
    }
    free(node);
}

int main() {
    char pre_str[55], in_str[55];
    scanf("%s", pre_str);
    scanf("%s", in_str);
    Node *root = build(pre_str, in_str, strlen(pre_str));
    post_order(root);
    printf("\n");
    post_order1(root);
    printf("\n");
    clear(root);
    return 0;
    
}
