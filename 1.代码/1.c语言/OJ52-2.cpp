/*************************************************************************
	> File Name: OJ52-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月13日 星期三 17时45分32秒
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
#define MAX_N 1000000
#define SQ(a) ((a) * (a))
long long c[MAX_N + 5], sum[MAX_N + 5];
long long f[MAX_N + 5], dp[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;
long long n, M;

void set(int i, int j) {
    dp[i] = dp[j] + SQ(sum[i] - sum[j]) + M;
    f[i] = dp[i] + SQ(sum[i]);
    return ;
}

double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (sum[i] - sum[j]);
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) cin >> c[i], sum[i] = sum[i - 1] + c[i];
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        while (tail - head >= 2 && slope(q[head], q[head + 1]) <= 2 * sum[i]) ++head;
        set(i, q[head]);
        while (tail - head >= 2 && slope(q[tail - 1], q[tail - 2]) > slope(q[tail - 1], i)) --tail;
        q[tail++] = i;
    }
    cout << dp[n] << endl;
    return 0;
}
