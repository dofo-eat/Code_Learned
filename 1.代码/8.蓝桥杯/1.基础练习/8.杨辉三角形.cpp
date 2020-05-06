/*************************************************************************
	> File Name: 8.杨辉三角形.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 14时54分28秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for(int i = 2; i < n; i++) {
        for(int j = 1; j <= i - 1; j++) {
            a[i][j] = a[i-1][j-1] + a[i - 1][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << a[i][j];
            i < n && cout << " ";
        }
        cout << endl;
    }
    return 0;
}
