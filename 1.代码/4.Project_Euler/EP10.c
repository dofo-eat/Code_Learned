/*************************************************************************
	> File Name: EP10.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月19日 星期四 18时49分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 2000000
long long int sum;

int prime[N + 5] = {0};

void init() {
    for(int i = 2; i <= N; i++) {
        if(prime[i]) continue;
        for(int j = i; j <= N; j += i) {
            prime[j] =  1;
        }
        sum += i;
    }
    printf("%lld\n", sum);
    return ;
}

int main() {
    init();
    //printf("%lld\n", sum);
    return 0;
}
