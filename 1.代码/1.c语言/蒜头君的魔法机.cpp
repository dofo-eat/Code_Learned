/*************************************************************************
	> File Name: 蒜头君的魔法机.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月17日 星期一 14时10分01秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int *data;
    int size, top;
}Stack;

void init(Stack *s, int n) {
    s->data = (int *)malloc (sizeof(int) * n);
    s->size = n;
    s->top = -1;
}

int push(Stack *s, int val) {
    if(s == NULL) return 0;
    if(s->top + 1 >= s->size) return 0;
    s->data[++(s->top)] = val;
    return 1;
}

int empty(Stack *s) {
    return s->top == -1;
}

int pop(Stack *s) {
    if(empty(s)) return 0;
    s->top--;
    return 1;
}

int top (Stack *s) {
    return s->data[s->top];
}

void clear(Stack *s){
    free(s->data);
    free(s);
}
int main () {
    int n, m;
    int x = 0, flag = 1;
    scanf("%d", &n);
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init(s, n);
    for(int i = 0; i < n; i++ ){
        scanf("%d", &m);
        for(int j = x; j < m; j++) {
            push(s, j);
        }
        if(empty(s) || top(s) != m) {
            flag = 0;
        }
        pop(s);
    }
    if(flag = 0) printf("NO\n");
    printf("YES\n");
    clear(s);
    return 0;
}
