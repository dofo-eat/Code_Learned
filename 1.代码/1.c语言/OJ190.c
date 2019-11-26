/*************************************************************************
	> File Name: OJ190.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月19日 星期二 20时29分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_N 8000000
typedef long long ll;

ll prime[MAX_N + 5];

void init() {
    for (ll i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (ll j = 2; j * i <= MAX_N; j++) {
            prime[i * j] = 1;
        }
    }
    return;
}

int main() {
    init();
    ll n, sum = 0;
    scanf("%lld", &n);
    for (ll i = 2; 2 * i <= n; i++) {
        (!prime[i] && !prime[n - i]) && (sum++);
       // if (prime[i] == 0 && prime[n - i] == 0) sum++;
    }
    printf("%lld\n", sum);
    return 0;
}
