/*************************************************************************
	> File Name: OJ490-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月29日 星期五 17时36分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

int func(int n, int m) {
    if(n == 1) return 0;
    return (func(n - 1, m) + m) % n;
}

int main() {
    int n, t, raw;
    cin >> n;
    raw = t = n;
    while(1) {
        n = func(n, 2) + 1;
        if(t == n) break;
        t = n;
    }
    cout << raw + t << endl;
}
