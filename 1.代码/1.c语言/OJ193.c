/*************************************************************************
	> File Name: OJ193.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月22日 星期五 18时06分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
int main() {
    ll n;
    scanf("%lld", &n);
    ll a[n];
    for(ll i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll k, s;
    scanf("%lld %lld",&k, &s);
    ll sum = 0;
    sum = s - k;
    int flag = 0;
    for(ll i = 0; i < n; i++) {
        if(sum == a[i]) {
            flag = 1;
        }
    }
    if(flag == 0) {
        printf("No");
    }else{
        printf("Yes");
    }
    return 0;
}

