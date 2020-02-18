/*************************************************************************
	> File Name: 6.binary_tree.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月15日 星期六 15时59分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree{
    Node *root;
    int n;
}Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild =  p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insertNode(Node *root, int val, int *ret) {
    //ret 是否创建节点成功
    if(root == NULL) {
        *ret = 1;
        return getNewNode(val);
    }
    if(root->data == val) return root;
    if(val < root->data) root->lchild = insertNode(root->lchild, val, ret);
    else root->rchild = insertNode(root->rchild, val, ret);
    return root;
}

void insert(Tree *tree, int val) {
    int flag  = 0;
    tree->root = insertNode(tree->root, val, &flag);
    tree->n += flag;
    return ;
}

void outputNode(Node *root) {
    if(root == NULL) return ;
    printf("%d ", root->data);
    if(root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
}
//二叉树转广义表

void output(Tree *tree) {
    printf("tree(%d) = [", tree->n);
    outputNode(tree->root);
    printf("]\n");
    return ;
}
//广义表样式输出

void pre_orderNode(Node *root) {
    if(root == NULL) return ;
    printf("%d ", root->data);
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return ;
}



void pre_order(Tree *tree) {
    printf("pre_order: ");
    pre_orderNode(tree->root);
    printf("\n");
    return ;
}
//前序遍历

void in_orderNode(Node *root) {
    if(root == NULL) return ;
    printf("%d ", root->data);
    in_orderNode(root->lchild);
    in_orderNode(root->rchild);
    return ;
}

void in_order(Tree *tree) {
    printf("in_order: ");
    in_orderNode(tree->root);
    printf("\n");
    return ;
}
//中序遍历
void post_orderNode(Node *root) {
    if(root == NULL) return ;
    printf("%d ", root->data);
    post_orderNode(root->lchild);
    post_orderNode(root->rchild);
    printf("%d ", root->data);
    return ;
}

void post_order(Tree *tree) {
    printf("post_order: ");
    post_orderNode(tree->root);
    printf("\n");
    return ;
}

void clear_Node(Node *node) {
    if(node == NULL) return ;
    clear_Node(node->lchild);
    clear_Node(node->rchild);
    free(node);
    return ;
}

void clear_tree(Tree *tree) {
    if(tree == NULL) return ;
    clear_Node(tree->root);
    return ;
}

int main () {
    srand(time(0));
    Tree *tree = getNewTree();
    #define max_op 10
    for(int i = 0; i < max_op ; i++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);
    return 0;
}
