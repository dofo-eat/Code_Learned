/*************************************************************************
	> File Name: EP07-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月17日 星期二 19时09分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 200000

int prime[N + 5] = {0};

void init() {
    for(int i = 2; i <= N; i++) {
        if(prime[i]) continue;//当前数字为合数
        prime[++prime[0]] = i;
        for(int j = i * i; j <= N; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
