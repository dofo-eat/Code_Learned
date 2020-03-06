/*************************************************************************
	> File Name: 蒜头君的新玩具.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月06日 星期五 21时22分02秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Heap {
    double *data;
    int size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (double *)malloc(sizeof(double) * length_input);
    h->size = 0;
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, double value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while (h->data[current] > h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

double top(Heap *h) {
     return h->data[0];
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
    int max_value = pos;
    if (lchild < n && h->data[lchild] > h->data[max_value]) {
        max_value = lchild;
    }
    if (rchild < n && h->data[rchild] > h->data[max_value]) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[pos], &h->data[max_value]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

int heap_size(Heap *h) {
    return h->size;
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int n, ans = 0;
    double a, b, temp;
    scanf("%d", &n);
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    init(heap, n + 5);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &a);
        push(heap, a);
    }
    for(int i = 1; i < n; i++) {
        a = top(heap);
        pop(heap);
        b = top(heap);
        pop(heap);
        temp = pow(a, 1.0 / 3.0) * pow(b, 2.0/ 3.0);
        push(heap, temp);
    }
    printf("%lf\n", top(heap));
    clear(heap);
    return 0;
}

