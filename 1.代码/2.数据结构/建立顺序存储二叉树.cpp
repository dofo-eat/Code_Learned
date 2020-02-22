/*************************************************************************
	> File Name: 建立顺序存储二叉树.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月21日 星期五 17时02分06秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *lchild, *rchild;
}Node, *pNode;

pNode init(char data) {
    pNode p = (pNode)malloc (sizeof(Node));
    p->data = data;
    p->lchild = p->rchild = NULL;
    return p;
}

void chear(pNode p) {
    if(!p) return ;
    if(p->lchild) {
        clear(p->lchild);
    }
    if(p->rchild) {
        clear(p->rchild);
    }
    free(p);
}

void output(pNode p) {
    if(!p) return ;
    printf("%c", p->data);
    if(p->lchild == NULL && p->rchild == NULL) return ;
    printf("(");
    if(p->lchild) {
        output(p->lchild);
    }
    if(p->rchild) {
        printf(",");
        output(p->rchild);
    }
    printf(")");
}

int main() {
    int len = 0, size = 50;
    char *str = (char *)malloc (sizeof(char) * size);
    char ch;
    str[0];
    while(scanf("%c", &ch)) {
        if(ch == '$') break;
    
        str[len] = ch;
        len++;
        if(len == size) {
            size *= 2;
            str = realloc(str, size);
        }
     pNode *p_arr = (pNode *)malloc(sizeof(pNode) * strlen(str)/ 2 + 1);
    int ind = 1;
    p_arr[ind] == NULLl
        for(int i = 0; i < len; i++) {
            if(str[i] == ' ')continue;
            p_arr[ind] = init(str[i]);
            if(ind != 1) {
                if(ind % 2) {
                    p_arr[ind / 2]->rchild = p_arr[ind];
                }else{
                    p_arr[ind / 2]->lchild = p_arr[ind];
                }
            }
            ++ind;
        }
        output(p_arr[l]);
        printf("\n");
        clear(p_arr[l]);
        free(p_arr);
        free(str);
        return 0;
    }
}
