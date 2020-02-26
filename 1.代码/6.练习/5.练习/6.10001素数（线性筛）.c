/*************************************************************************
	> File Name: 6.10001素数（线性筛）.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月24日 星期二 14时26分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000000

int prime[N + 5] = {0};

void init() {
    for(int i = 2; i <= N; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i >= N) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
