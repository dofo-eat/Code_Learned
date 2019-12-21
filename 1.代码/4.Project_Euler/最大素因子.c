/*************************************************************************
	> File Name: 最大素因子.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月17日 星期二 20时18分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 10000

int prime[N + 5] = {0};

void init() {
    for(int i = 2; i <= N; i++) {
        if(prime[i]) continue;
        for(int j = i; j <= N; j += i) {
            prime[j] = i;           
        }        
    }
    return ;
}

int main() {
    init();
    int n;
    while(~scanf("%d", &n)) {
        printf("最大素因子%d = %d\n", n, prime[n]);    
    }
    return 0;
}


