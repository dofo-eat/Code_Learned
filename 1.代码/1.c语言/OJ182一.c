/*************************************************************************
	> File Name: OJ182一.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 14时21分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n; 
    scanf("%d", &n);
    int max = 0;
    int a[100000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > max) {
            max = a[i];
        }
    }
    printf("%d", max);
    return 0;
}
