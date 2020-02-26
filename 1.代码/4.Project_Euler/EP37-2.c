/*************************************************************************
	> File Name: EP37-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 20时23分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000000

int prime[N + 5] = {0};
int is_prime[N + 5] = {1,1,0};

void init() {
    for(int i = 2; i < N; i++) {
        if(!is_prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > N) break;
            is_prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_val(int n) {
    int digit = floor(log10(n)) + 1;
    int h = pow(10, digit - 1);
    int tmp = n;
    for(int i = 1; i < digit - 1; i++) {
        tmp /= 10;
        if(is_prime[tmp]) return 0;
    }
    tmp = n;
    for(int i = 0; i < digit - 1; i++) {
        tmp %= 10;
        if(is_prime[tmp]) return 0;
        h /= 10;
    }
    return 1;
}

int main() {
    init();
    int flag = 11, sum= 0;
    for(int i = 1; i <= prime[0] && flag; i++) {
        if(prime[i] < 10) continue;
        if(!is_val(prime[i])) continue;
        sum += prime[i];
        flag -= 1;
        flag && printf("%d\n", prime[i]);
    }
    return 0;
}
