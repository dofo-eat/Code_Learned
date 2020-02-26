/*************************************************************************
	> File Name: 1.最大值因数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月23日 星期一 00时02分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 600851475143

typedef long long ll;

int main () {
    ll ans = 0; 
    ll m = N;
    ll i = 2;
    while(i * i <= m) {
        if(m % i == 0) ans = i;
        while(m % i == 0) m /= i;
        i += 1;
    }
    if(m > 1) ans = m;
    cout << ans << endl;
    return 0;
}
