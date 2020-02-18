/*************************************************************************
	> File Name: 稀疏多项式.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月15日 星期六 12时42分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Vector{
    int *data, *data2;
    int size, length;
}Vector;

int init(Vector *vec, int size) {
    vec->data = (int *)malloc(sizeof(int) *size);
    vec->data2 = (int *)malloc(sizeof(int) *size);
    vec->size = size;
    vec->length = 0;
    if(vec->data == NULL || vec->data2) return 0;
    return 1;
}

void expand(Vector *vec) {
    int *old_data = vec->data;
    int *old_data2 = vec->data2;
    vec->size *= 2;
    vec->data = (int *)malloc(sizeof(int) *vec->size);
    vec->data2 = (int *)malloc(sizeof(int) *vec->size);
    for(int i = 0; i < vec->length; i++) {
        vec->data[i] = old_data[i];
        vec->data2[i] = old_data2[i];
    }
    free(old_data);
    free(old_data2);
}

int insert(Vector *vec, int loc, int val, int val2) {
    if(loc < 0 || loc > vec->length) return 0;
    if(vec->length >= vec->size) expand(vec);
    for(int i = vec->length; i > loc; i--) {
        vec->data[i] = vec->data[i - 1];
        vec->data2[i] = vec->data2[i - 1];
    }
    vec->data[loc] = val;
    vec->data2[loc] = val2;
    vec->length++;
    return 1;
}

void output(Vector *vec, int num) {
    int ans = 0;
    for(int i = 0; i < vec->length; i++) {
        ans += vec->data[i] * pow(num, vec->data2[i]);
    }
    printf("%d\n", ans);
    return ;
}

void clear(Vector *vec) {
    free(vec->data);
    free(vec);
}

int main () {
    int m, x;
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    scanf("%d", &m);
    init(vec, m);
    int a, b;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        insert(vec, i, a, b);
    }
    scanf("%d", &x);
    output(vec, x);
    clear(vec);
    return 0;
}
