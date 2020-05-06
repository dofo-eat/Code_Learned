/*************************************************************************
	> File Name: OJ591.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 20时32分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if(n % 2 == 0) {
        int mid = n / 2;
        if(m <= mid) cout << m + 1 << endl;
    } else {
        int mid = (n + 1) / 2;
        if(m < mid) cout << m + 1;
        else cout << m - 1;
    }
    return 0;
}
