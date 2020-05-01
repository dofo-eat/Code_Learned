/*************************************************************************
	> File Name: OJ43-4.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月30日 星期四 18时35分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000
int f[MAX_N + 5][MAX_N + 5];

int main () {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j= 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }
    //倒叙进行判断
   /* for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            f[i][j] += max(f[i+ 1][j], f[i + 1][j + 1]);
        }
    }
    cout << f[1][1] << endl;*/
    //正序
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            f[i][j] += max(f[i- 1][j], f[i - 1][j - 1]);
        }
    }
    return 0;
}
