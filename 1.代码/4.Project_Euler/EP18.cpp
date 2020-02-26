/*************************************************************************
	> File Name: EP18.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月28日 星期六 16时18分26秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 20

int val[N + 5][N + 5] = {0};
int keep[N + 5][N + 5] = {0};
int dfs(int i, int j, int n) {
    if(i + 1 == n) return val[i][j];
    if(keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n);//n是上界
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] =  (val1 > val2 ? val1: val2) + val[i][j];
}

int main () {
    for(int i = 0; i <= 15; i++) {
        for(int j = 0; j < i; j++) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, N) << endl;
    return 0;
}
