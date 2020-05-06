/*************************************************************************
	> File Name: OJ589.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 18时44分08秒
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
    return a;
    return gcd(b, a % b);
}

int main() {
    int n, k, id;
    cin >> n >> k >> id;
    if(n == k) {
        cout << "1/1" << endl;
    }
    else if(k == 0) {
        cout << "0/1" << endl;
    } else{
        int temp = gcd(n, k);
        cout << k / temp << "/" << n / temp << endl;
    }
    return 0;
}
