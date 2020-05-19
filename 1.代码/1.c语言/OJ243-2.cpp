/*************************************************************************
	> File Name: OJ243-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月19日 星期二 18时03分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
#define MAX_N 200000
struct Data {
    long long s, e, d;
} arr[MAX_N + 5];

long long count(long long n, long long pos) {
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        if (arr[i].s > pos) continue;
        if (arr[i].e <= pos) {
            sum += (arr[i].e - arr[i].s) / arr[i].d + 1;
            continue;
        }
        sum += (pos - arr[i].s) / arr[i].d + 1;
    }
    return sum;
}

long long check(long long n, long long pos) {
    return count(n, pos) % 2;
}

long long bs(long long l, long long r, long long n) {
    if (l == r) return l;
    long long mid = (l + r) >> 1;
    if (check(n, mid)) return bs(l, mid, n);
    return bs(mid + 1, r, n);
}

void solve() {
    long long n, l, r;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].e >> arr[i].d;
        if (i == 0) l = arr[i].s, r = arr[i].e;
        l = min(l, arr[i].s);
        r = max(r, arr[i].e);
    }
    long long pos = bs(l, r, n);
    long long cnt = count(n, pos) - count(n, pos - 1);
    if (cnt % 2) {
        cout << pos << " " << cnt << endl;
    } else {
        cout << "Poor QIN Teng:(" << endl;
    }
    return ;
}

int main() {
    long long tcase;
    cin >> tcase;
    while (tcase--) solve();
    return 0;
}

