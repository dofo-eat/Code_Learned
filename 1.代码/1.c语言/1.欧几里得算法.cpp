/*************************************************************************
	> File Name: 1.欧几里得算法.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月12日 星期日 13时37分08秒
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}
