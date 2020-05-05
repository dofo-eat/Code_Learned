/*************************************************************************
	> File Name: OJ258.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月05日 星期二 21时14分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 100
int g[MAX_N + 5][MAX_N + 5];

int main() {
    int n, ans = -128;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            ans = max(ans, g[i][j]);
            g[i][j] += g[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int sum = 0, pre_min = 0;
            for (int k = 1; k <= n; k++) {
                sum += g[j][k] - g[i - 1][k];
                ans = max(ans, sum - pre_min);
                pre_min = min(pre_min, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
