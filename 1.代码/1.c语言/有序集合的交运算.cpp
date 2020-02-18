/*************************************************************************
	> File Name: 有序集合的交运算.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月14日 星期五 21时21分09秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct Vector{
    int *data;
    int length, size;
}Vector;

int init(Vector *vec, int size) {
    vec->data = (int *)malloc(sizeof(int) *size);
    vec->size = size;
    if(vec->data == NULL) return 0;
    vec->length = 0;
    return 1;
}

void expand(Vector *vec) {
    int *old_data = vec->data;
    vec->size = vec->size * 2;
    vec->data = (int *)malloc(sizeof(int) *vec->size);
    for(int i = 0; i < vec->length; i++) {
        vec->data[i] = old_data[i];       
    }
    free(old_data);
}

int insert(Vector *vec, int loc, int val) {
    if(loc < 0 || loc > vec->length) return 0;
    if(vec->length >= vec->size) expand(vec);
    for(int i = vec->length; i > loc; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[loc] = val;
    vec->length++;
    return 1;
}

void output(Vector *vec) {
    printf("%d\n", vec->length);
    for(int i = 0; i < vec->length; i++) {
        printf("%d", vec->data[i]);
        i < vec->length - 1 && printf(" ");
    }
    printf("\n");
    return ;
}

void f(Vector *vec1, Vector *vec2, Vector *vec3) {
    int i = 0, j = 0, k = 0;
    while(i < vec1->length &&j < vec2->length) {
        if(vec1->data[i] < vec2->data[j]) i++;
        else if(vec1->data[i] > vec2->data[j]) j++;
        else {
            insert(vec3, k++, vec1->data[i]);
            i++, j++;
        }
    }
}

void clear(Vector *vec) {
    free(vec->data);
    free(vec);
}

int main() {
    int n, m;
    int a, b;
    Vector *vec1 = (Vector*)malloc(sizeof(Vector));
    init(vec1, n);
    Vector *vec2 = (Vector*)malloc(sizeof(Vector));
    init(vec2, m);
    Vector *vec3 = (Vector*)malloc(sizeof(Vector));
    init(vec3, vec1->size + vec2->size);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        insert(vec1, i, a);
    }
    scanf("%d", &m);
    for(int j = 0; j < m; j++){
        scanf("%d", &b);
        insert(vec2, j, b);
    }
    f(vec1, vec2, vec3);
    output(vec3);
    clear(vec1);
    clear(vec2);
    clear(vec3);
    return 0;
}
