/*************************************************************************
	> File Name: EP07-3.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月17日 星期二 19时54分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 10000

int prime[N + 5] = {0};

int ps[N + 5] = {0};

void init() {
    for(int i = 2; i <= N; i++) {
        if(prime[i]) continue;
        for(int j = i; j <= N; j += i) {
            if(prime[j]) continue;
            prime[j] = i;
        }
    }
    return ;
}

int main() {
    init();
    int n;
    while(~scanf("%d", &n)) {
        printf("最小素因子%d = %d\n", n, prime[n]);
    }
    return 0;
}
