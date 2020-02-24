/*************************************************************************
	> File Name: 报数游戏.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月21日 星期五 14时00分14秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define max 10000005

int search(int *a, int n, int value) {
    int l = 0, r = n - 1;
    int mid;
    while(l < r) {
        mid = (l + r + 1) / 2;
        if(a[mid]== value) return mid;
        else if(a[mid]> value) r = mid - 1;
        else l = mid;
    }
    return l;
}

int main () {
    int n, m;
    int b;
    scanf("%d %d", &n, &m);
    int *a = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &b);
        printf("%d", a[search(a, n, b)]);
        i < m - 1 && printf(" ");
    }
    free(a);
    return 0;
}
