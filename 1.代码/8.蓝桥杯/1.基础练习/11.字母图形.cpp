/*************************************************************************
	> File Name: 11.字母图形.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 15时49分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

char mmap[10000][30];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        mmap[0][i] = (char)'A' + i;
    }
    for(int j = 0; j < n; j++) {
        mmap[j][0] = (char)'A' + j;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            mmap[i][j] = mmap[i - 1][j - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mmap[i][j];
        }
        cout << endl;
    }
    return 0;
}
