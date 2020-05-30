/*************************************************************************
	> File Name: OJ226.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 12时09分38秒
 ************************************************************************/
#include<iostream>
using namespace std;

long long quick_mod(long long a, long long b, long long p) {
    long long temp = a, ans = 1; 
    while(b) {
        if(b & 1) ans = ans * temp % p;
        temp = temp * temp % p;
        b >>= 1;
    }
    return ans % p;
} 

int main() {
    long long a, b, p;
    cin >> a >> b >>p;
    cout << quick_mod(a, b, p) << endl;
    return 0;
} 
