/*************************************************************************
	> File Name: OJ318.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月08日 星期日 16时04分14秒
 ************************************************************************/

#include<iostream>
using namespace std;


typedef long long ll;

void ex_gcd(ll a, ll b, ll *x, ll *y) {
    if(b == 0) {
        *x = 1;
        *y = 0;
        return ;
    }
    ex_gcd(b, a % b, y, x);
    *y -= a / b * (*x);
    return ;
}

int main () {
    ll a, b, x, y;
    while(cin >> a >> b) {
        ex_gcd(a, b, &x, &y);
        ll t = b;
        cout << ((x + t) % t + t) % t;
    }
    return 0;
}
