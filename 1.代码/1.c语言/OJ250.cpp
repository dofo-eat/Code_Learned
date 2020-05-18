/*************************************************************************
	> File Name: OJ250.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月17日 星期日 20时11分11秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 10000000
long long int a[MAX_N + 5];
long long int s[MAX_N + 5];
long long int g[MAX_N + 5];
long long int n, sum = 0, c, ans = 0;

int main() {
    cin >> n;
    for(long long int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        sum += a[i];
    }
    c = sum / n;
    for(long long int i = 1; i <= n; i++) {
        g[i] = s[i] - i * c;
    }
    sort(g + 1, g + 1 + n);
    c = g[n / 2];//中位数
    for(long long int i = 1; i <= n; i++) {
        ans +=  abs(g[i] - c);
    }
    cout << ans << endl;
    return 0;
}
