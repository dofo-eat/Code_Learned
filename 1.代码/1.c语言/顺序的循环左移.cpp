/*************************************************************************
	> File Name: 顺序的循环左移.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月14日 星期五 11时21分18秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct Vector{
    int *data;
    int size, length;
}Vector;

int init(Vector *vec, int size) {
    vec->data = (int *) malloc (sizeof(int) * size);
    vec->size = size;
    if(vec->data == NULL) return 0;
    vec->length = 0;
    return 1;
}

void expand(Vector *vec) {
    int *old_data = vec->data;
    vec->size *= 2;
    vec->data = (int *)malloc(sizeof(int) *vec->size);
    for(int i = 0; i < vec->length; i++) {
        vec->data[i] = old_data[i];
    }
    free(old_data);
}

int insert (Vector *vec, int loc, int val) {
    if(loc < 0 || loc > vec->length) return 0;
    if(vec->length >= vec->size) {
        expand(vec);    
    } 
    for(int i = vec->length; i > loc; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[loc] = val;
    vec->length++;
    return 1;
}

int reverse(Vector *vec, int begin, int end) {
    int temp;
    while(begin < end) {
        temp = vec->data[begin];
        vec->data[begin] = vec->data[end];
        vec->data[end] = temp;
        begin++;
        end--;
    }
    return 1;
}

void output(Vector *vec) {
    for(int i = 0; i < vec->length; i++) {
        printf("%d", vec->data[i]);
        i < vec->length - 1 && printf(" ");
    }
    printf("\n");
    return ;
}

void clear(Vector * vec) {
    if(vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
}

int main () {
    int n, k, a;
    Vector *vec =(Vector*) malloc(sizeof(Vector));
    scanf("%d %d", &n, &k);
    init(vec, n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        insert(vec, i, a);
    }
    reverse(vec, 0, k - 1);
    reverse(vec, k, n - 1);
    reverse(vec, 0, n - 1);
    output(vec);
    clear(vec);
    return 0;
}
