/*************************************************************************
	> File Name: EP37.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 20时01分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX_N 1000000
typedef long long ll;

ll prime[MAX_N] = {0};
void init() {
    for (ll i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (ll j = 1; j <= prime[0] && prime[j] * i  < MAX_N; j++) {
            prime[i * prime[j]] = 1;
                if(i % prime[j] == 0) break;    
        }   
    }
}

int is_val(int n) {
    int digit = floor(log10(n));
    int h = pow(10, digit);
    if(n > 10) {
        int x = n;
        int flag = 0;
        while(digit--) {
            for(int i = 1; i <= prime[0]; i++) {
                if(x % h == prime[i])
                h /= 10;
                else flag = 1;
            }          
        }
        if(flag = 1) return 0;
        return 1;
    }   
}

int main() {
    init();
    int sum = 0;
    for(int i = 2; i < MAX_N; i++) {
        if(is_val(i))
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
