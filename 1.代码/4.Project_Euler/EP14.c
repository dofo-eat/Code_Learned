/*************************************************************************
	> File Name: EP14.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月21日 星期六 14时13分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000000
typedef long long ll;

ll get_len(ll n) {
    if(n == 1) return 1;
    if(n % 2 == 0) return get_len(n / 2) + 1;
    return get_len(3 * n + 1) + 1;
}

int main() {
    ll ans = 0, len = 0;    
    for(ll i = 1; i < N; i++) {
        ll temp = get_len(i);
        if(temp > len) {
            ans = i;
            len = temp;
        }
    }
    printf("num = %lld, len = %lld\n", ans , len);
    return 0;
}
