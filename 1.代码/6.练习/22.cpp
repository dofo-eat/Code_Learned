/*************************************************************************
	> File Name: 22.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 14时52分20秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 10000

int x[MAX_N + 5];
int y[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for(int i = 1; i <= n; i++) {
        x[i] = x[i] - i;
    }
    sort(x + 1, x +  n + 1);
    int cx = x[n / 2 + 1], cy = y[n / 2 + 1];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += abs(x[i] - cx);
        ans += abs(y[i] - cy);
    }
    cout << ans << endl;
    return 0;
}
