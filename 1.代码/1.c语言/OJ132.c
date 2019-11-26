/*************************************************************************
	> File Name: OJ132.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月08日 星期五 17时18分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int a[10001];
    long long int sum = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        sum *= a[i];
    }
    printf("%lld",sum);
    return 0;
}
