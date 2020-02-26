/*************************************************************************
	> File Name: EP18-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月28日 星期六 16时51分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 20

int val[N + 5][N + 5] = {0};

int main () {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    for(int i = N - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            val[i][j] += max(val[i + 1][j], val[i + 1][j + 1]);
        }
    }
    cout << val[0][0] << endl;
    return 0;
}
