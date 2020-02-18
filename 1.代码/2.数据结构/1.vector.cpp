/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月11日 星期二 14时51分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct vector{
    int *data;
    int size, length;
}vector;
//*data 连续的空间

vector *init(int n) {
    vector *vec = (vector *) malloc(sizeof(vector));
    vec->data = (int *) malloc (sizeof(int) * n);
    vec-> size = n;
    vec->length = 0;
    return vec;
}
//顺序表的初始化

int expand(vector *vec) {
    int extra_size = vec->size;
    int *p;
    while(extra_size) {
        p = (int *)realloc(vec->data, sizeof(int) * (vec->size + extra_size));
        if(!p) break;
        extra_size /= 2;
    }
    if(p == NULL) return 0;
    vec->data = p;
    vec->size += extra_size;
    return 1;
}
//calloc 开辟空间可以清零 realloc 对当前空间重新进行开辟

int insert(vector *vec, int ind, int val) {
    if(vec == NULL) return 0;
    if(ind < 0 || ind > vec->length) return 0;
    if(vec->length == vec->size) {
        if(!expand(vec)) return 0;//扩容失败在输出失败
        printf("expand seccessfully ! size = %d\n",vec->size);
    }
    for(int i = vec->length; i > ind; i--) {
        vec->data[i] = vec ->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erase(vector *vec, int ind) {
    if(vec == NULL) return 0;
    if(ind < 0 || ind >= vec->length) return 0;
    for(int i = ind + 1; i < vec->length; i++) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length -= 1;
    return 1;
}

void output(vector *vec) {
    printf("vector(%d) = [", vec->length);
    for(int i = 0; i < vec->length; i++) {
        i && printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(vector *vec) {
    if(vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
}
//顺序表的清空

int main () {
    srand(time(0));
    #define max_op 20
    vector *vec = init(max_op);
    int op, ind, val;
    for(int i = 0; i < max_op; i++) {
        op = rand() % 4;
        ind = rand() % (vec->length + 3) - 1;
        val = rand() % 100;
        //为什么加1因为对0%是非法的
        switch(op) {
            case 0:
            case 1:
            case 2:{
                printf("insert %d at %d to vector = %d\n", val, ind, insert(vec, ind, val));
            }break;
            case 3:{
                printf("erase item at %d from vector = %d\n", ind, erase(vec, ind));
            }break;
        }
        output(vec);
        printf("\n");
    }
    clear(vec);
    return 0;
}
