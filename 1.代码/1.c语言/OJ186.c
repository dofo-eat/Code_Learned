/*************************************************************************
	> File Name: OJ186.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月19日 星期二 18时35分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]); 
    }
    for(int j = 0; j < n; ) {
        j = a[j] + j;
        sum++;
    }
    printf("%d", sum);
    return 0;
}
