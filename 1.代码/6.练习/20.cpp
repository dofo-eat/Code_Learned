/*************************************************************************
	> File Name: 20.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 14时00分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 200000

int a[MAX_N + 5];
int b[MAX_N + 5];

inline int lowbit(int x) {
    return x &(-x);
}

void add(int x, int val, int n) {
    while (x <= n) {
        b[x] += val;
        x += lowbit(x);
    }
}

int f(int x) {
    if(x) {
        return b[x] + f(x - lowbit(x));
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    long long ans = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        long long lnum = f(a[i]);
        ans += (a[i] - lnum - 1) * lnum;
        sum += (i - 1- lnum) * (n - a[i] - i + 1 + lnum);
        add(a[i], 1, n);
    }
    cout << sum << " " << ans << endl;
    return 0;
}
