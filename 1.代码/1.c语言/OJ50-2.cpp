/*************************************************************************
	> File Name: OJ50.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月12日 星期二 18时54分16秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 32
#define MAX_M 65536
long long int  dp[MAX_N + 5][MAX_M + 5];

int  main() {
    long long int  n, m;
    cin >> n >> m;
    if(n == 1) {
        cout << m << endl;
        return 0;
    }
    for(long long int  k = 1; k <= MAX_M; k++) dp[1][k] = k;
    for(long long int  i = 2; i <= n; i++) {
        for(long long int  k = 1; k <= MAX_M; k++) {
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    long long int  p = 1;
    while (dp[n][p] < m) p++;
    cout << p << endl;
    return 0;
}
