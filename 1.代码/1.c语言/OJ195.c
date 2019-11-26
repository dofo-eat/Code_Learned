/*************************************************************************
	> File Name: OJ195.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月22日 星期五 20时13分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
ll f(ll l, ll r, ll a[], ll b) {
    ll mid;
        while(l <= r) {
            mid = (l + r) / 2;
                if(a[mid] == b) return a[mid];
                else if(a[mid] > b) r = mid - 1;
                else l = mid + 1;
        }
        if(a[0] > b) {
            return a[0];
        } 
        return a[r];
}
int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll a[n], b;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int j = 0; j < m; j++) {
        scanf("%lld", &b);
        printf("%lld",f(0, n - 1, a, b));
        j < m - 1 && printf(" ");
    }
    return 0;
}
