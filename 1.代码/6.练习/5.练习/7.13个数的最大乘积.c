/*************************************************************************
	> File Name: 7.13个数的最大乘积.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月24日 星期二 17时33分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000

char num[N + 5] = {0};

int main() {
    int len = 0;
    while(~scanf("%d", num + len)) len += strlen(num + len);
    long long int ans = 0, p = 1, zero = 0;
    for(int i = 0; num[i]; i++) {
        num[i] -= '0';
        if(num[i]) p *= num[i];
        else zero += 1;
        if(i < 13) continue;
        if(i < num[i - 13]) p /= num[i - 13];
        else zero -= 1;
        if(zero == 0 && p > ans) ans = p;
    }
    printf("%d\n", ans);
    return 0;
}
