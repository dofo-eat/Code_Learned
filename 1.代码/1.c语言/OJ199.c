/*************************************************************************
	> File Name: OJ199.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月21日 星期四 20时53分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef long long ll; 
ll a[15];
ll ans[1000000];
ll f(ll x, ll m) {
    ll num = 0;
    if(x < 10) return x;
    if (ans[x]) return ans[x];
    for (int i = 0; i < 10; i++) num += (a[i] * f(x - i - 1, m) % m); 
    ans[x] = num % m;
    return ans[x];
}
int main() {
    ll k, m;
    scanf("%lld %lld", &k, &m);
    for(int i = 0; i < 10; i++) {
        scanf("%lld", &a[i]);
    }
    ll sum = f(k, m);
    printf("%lld", sum);
    return 0;
}
