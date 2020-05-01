/*************************************************************************
	> File Name: OJ44.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月30日 星期四 19时30分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
int dp[MAX_N + 5];
int a[MAX_N + 5];

int main () {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(a[j] >= a[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
