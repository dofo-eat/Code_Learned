/*************************************************************************
	> File Name: OJ194.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月22日 星期五 18时45分39秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    ll a[n];
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll s;
    scanf("%lld", &s);
    int flag = 0;
    for(ll i = 0; i < n && !flag; i++) {
        for(ll j = i + 1; j < n; j++) {
            if(a[j] == s - a[i]) {
                flag = 1;
                break;
            }
        }   
    }
    if(flag == 0) {
        printf("No");
    }else{
        printf("Yes");
    }
    return 0;
}
