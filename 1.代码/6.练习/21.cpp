/*************************************************************************
	> File Name: 21.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 14时21分29秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100000

long long n, m;
long long a[MAX_N + 5];
long long b[MAX_N + 5];
long long sum[MAX_N + 5];

bool check(long long mid) {
    for(int i = 1; i <= n; i++) {
        b[i] = a[i] - mid;
        sum[i] = b[i] + sum[i - 1];
    }   
    long long temp = 0;
    for(long long j = m; j <= n; j++) {
        temp = min(temp, sum[j - m]);
        if(sum[j] - temp >= 0) {
            return 1;
        }
    } 
    return 0;
}

long long bs(long long l, long long r) {
    if(l == r) return l;
    long long mid = (l + r + 1) / 2;
    if(check(mid)) return bs(mid, r);
    return bs(l, mid - 1);
}

int main () {
    cin >> n >> m;
    long long l, r;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    cout << bs(l, r) << endl;
    return 0;
}
