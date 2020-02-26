/*************************************************************************
	> File Name: EP45.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月24日 星期二 19时55分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
typedef long long ll;

ll Triangle(ll n) {
    return n * (n + 1) / 2;
}

ll Pentagonal(ll n) {
    return n * (3 * n - 1) / 2;
}

ll Hexagonal(ll n) {
    return n * (2 * n - 1);
}

ll binary_search(ll (*num)(ll), ll n, ll x) {
    ll head = 1, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(num(mid) == x) return mid;
        if(num(mid) < x) head = mid + 1;
        return tail = mid - 1;
    }
    return -1;
}

int main () {
    ll n = 144;
    while(binary_search(Pentagonal, 2 * n, Hexagonal(n)) == -1) n += 1;
    cout << Hexagonal(n) << endl;
    return 0;
}
