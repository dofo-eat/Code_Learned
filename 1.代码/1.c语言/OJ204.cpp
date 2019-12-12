/*************************************************************************
	> File Name: OJ204.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月11日 星期三 14时58分41秒
 ************************************************************************/

#include<iostream>
using namespace std;


int main () {
    int n;
    cin >> n;
    int a[35][35] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                cout << a[i][j];
            }
        }
        i < n - 1 && cout << endl;
    }
    return 0;
}
