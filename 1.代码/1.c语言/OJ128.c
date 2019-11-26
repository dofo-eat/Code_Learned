/*************************************************************************
	> File Name: OJ128.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月07日 星期四 20时49分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[10001];
    double sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%.2f", sum / n);
    return 0;
}
