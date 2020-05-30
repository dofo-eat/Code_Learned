/*************************************************************************
	> File Name: 17.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月29日 星期五 22时44分39秒
 ************************************************************************/
 
/*************************************************************************
    > File Name: 44.cpp
    > Author: huguang
    > Mail: hug@haizeix.com
    > Created Time: 四  4/30 19:30:16 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 1000000
#define INF 0x3f3f3f3f

int dp[MAX_N + 5];
int len[MAX_N + 5], ans = 0;
int a[MAX_N + 5];

int bs(int *len, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (len[mid] < x) return bs(len, mid + 1, r, x);
    return bs(len, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = INF;
    }
    len[++ans] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, a[i]);
        len[dp[i]] = a[i];
        ans = max(dp[i], ans);
    }
    cout << ans << endl; 
    return 0;
}

