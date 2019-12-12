/*************************************************************************
	> File Name: OJ455.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月07日 星期六 13时04分07秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int gcd(int m, int n) {
    if(m % n != 0) return gcd(n, m % n);
    else return n;
}
int main () {
    int a, b, c;
    cin >> a >> b >> c;
    int d[3] = {0};
    d[0] = a;
    d[1] = b;
    d[2] = c;
    sort(d, d + 3);
    int sum = gcd(d[2], d[0]);
    cout << d[0]/ sum << "/" << d[2]/sum << endl;
}
