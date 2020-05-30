/*************************************************************************
	> File Name: 16.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月29日 星期五 17时12分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 20
#define MAX_M 10000

int dp[MAX_N + 5][MAX_M + 5];
int val[MAX_N + 5];


int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= val[i]) dp[i][j] += dp[i][j - val[i]];
            dp[i][j] %= 9973;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
