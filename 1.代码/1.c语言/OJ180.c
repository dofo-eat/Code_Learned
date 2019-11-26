/*************************************************************************
	> File Name: OJ180.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月16日 星期六 20时26分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    long long int n;
    scanf("%lld", &n);
    long long int sum = 1;
    while(n != 0 && n--) {
         sum *= 2;
    }
    printf("%lld",sum);
    return 0;
}
