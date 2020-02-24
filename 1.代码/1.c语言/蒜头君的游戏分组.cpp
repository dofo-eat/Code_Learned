/*************************************************************************
	> File Name: 蒜头君的游戏分组.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月24日 星期一 18时00分15秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct DisjoinSet {
    int *father, *rank;
}DisjoinSet;

void init(DisjoinSet *s, int size) {
    s->father = (int *)malloc(sizeof(int) *size);
    s->rank = (int *)malloc(sizeof(int) *size);
    for(int i = 0; i < size; i++) {
        s->father[i] = i;
        s->rank[i] = 1;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max(int a, int b) {
    return a > b?a : b;
}

int find_set(DisjoinSet *s, int node) {
    if(s->father[node] != node) {
        s->father[node] = find_set(s, s->father[node]);
    }
    return s->father[node];
}

int merge(DisjoinSet *s, int node1, int node2) {
    int r1 = find_set(s, node1);
    int r2 = find_set(s, node2);
    if(r1 != r2) {
        if(s->rank[r1] > s->rank[r2]) {
            swap(&r1, &r2);
        }
        s->father[r1] = r2;
        s->rank[r2] = max(s->rank[r1] + 1, s->rank[r2]);
        return 1;
    }
    return 0;
}

void clear(DisjoinSet *s) {
    if(!s) return ;
    free(s->father);
    free(s->rank);
    free(s);
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    DisjoinSet *dsu = (DisjoinSet *)malloc(sizeof(DisjoinSet));
    init(dsu, n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        merge(dsu, a, b);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(dsu->father[i] != i) continue;
        ans++;
    }
    printf("%d\n", ans);
    clear(dsu);
    return 0;
}
