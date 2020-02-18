/*************************************************************************
	> File Name: 7.thread_tree.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月15日 星期六 19时12分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
    int ltag, rtag;
}Node;
//TAG线索

Node *getNewNode(int val) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    p->ltag = 0;
    p->rtag = 0;
    return p;
}
//0 NORMAL 1 THREAD

Node *insert(Node *root, int val) {
    if(root == NULL) return getNewNode(val);
    if(root->data == val) return root;
    if(val < root->data) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    return root;
}

void build_thread(Node *root) {
    if(root == NULL) return ;
    static Node *pre = NULL;
    build_thread(root->lchild);//线索向左子树建立
    if(root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = 1;
    }
    if(pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = 1;
    }
    pre = root;
    build_thread(root->rchild);
    return ;
}

Node *most_left(Node *p) {
    while(p != NULL && p->ltag == 0 && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

void output(Node *root) {
    Node *p = most_left(root);
    while(p) {
        printf("%d ", p->data);
        if(p->rtag == 1) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
    return ;
}

void in_order(Node *root) {
    if(root == NULL) return ;
    if(root->ltag == 0) in_order(root->lchild);
    printf("%d ", root->data);
    if(root->rtag == 0) in_order(root->rchild);
    return ;
}

void clear(Node *root) {
    if(root == NULL) return ;
    if(root->ltag == 0) clear(root->lchild);
    if(root->rtag == 0) clear(root->rchild);
    free(root);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Node *root = NULL;
    for(int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    //给当前建立线索
    output(root);
    printf("\n");
    in_order(root);
    printf("\n");
    clear(root);
    return 0;
}

