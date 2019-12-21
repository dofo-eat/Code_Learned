/*************************************************************************
	> File Name: EP14-3.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月21日 星期六 14时32分27秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000000

int keep[N + 5] = {0};

typedef long long ll;

ll get_len(ll n) {
    if(n == 1) return 1;
    if(n <= N && keep[n]) return keep[n];
    ll ret = 0;
    if(!(n & 1)) ret =  get_len(n >> 1) + 1;
    else ret =  get_len(3 * n + 1) + 1;
    if(n <= N) keep[n] = ret;
    return ret;
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

