/*************************************************************************
	> File Name: OJ36.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月27日 星期一 17时38分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum;
    return 0;
}
