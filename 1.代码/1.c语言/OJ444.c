/*************************************************************************
	> File Name: OJ444.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月03日 星期二 18时36分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n, x;
    scanf("%d", &n);
    int a[101];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    for(int j = 0; j < n - 1; j++) {
        if(j == (x - 1)) printf("%d ",a[n - 1]);
            printf("%d", a[j]);
        j < n - 2 && printf(" ");
    }
    return 0;
}
