/*************************************************************************
	> File Name: OJ467.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 19时42分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    long long int n;
    scanf("%lld", &n);
    long long int sum = 1;
    for(long long int i = 1; i <= n; i++) {
        sum *= i;
    }
    printf("%lld", sum);
    return 0;
}
