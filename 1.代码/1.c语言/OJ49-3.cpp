/*************************************************************************
	> File Name: OJ49-3.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月29日 星期三 20时05分35秒
 ************************************************************************/
#include <iostream>

using namespace std;
#define MAX_V 100000
int dp[MAX_V + 5];

int main() {
    int n, v, w, s, V;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        for (int k = 1; s > 0; s -= k, k *= 2) {
            k = min(k, s);
            for (int j = V; j >= k * v; j--) {
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}

