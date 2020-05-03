/*************************************************************************
	> File Name: OJ343.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月03日 星期日 13时21分30秒
 ************************************************************************/
#include <iostream>
using namespace std;

#define MAX_N 3000

int a[MAX_N + 5], b[MAX_N + 5];
int n, ans = 0;

int dp[MAX_N + 5][MAX_N + 5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (a[i] - b[j]) continue;
            dp[i][j] = max(1, dp[i][j]);
            for (int k = 1; k < i; k++) {
                if (a[k] >= a[i]) continue;
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}

