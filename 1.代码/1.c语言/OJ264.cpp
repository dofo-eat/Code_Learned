/*************************************************************************
	> File Name: OJ264.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月28日 星期二 20时37分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

long long int a[MAX_N + 5];
long long int s[MAX_N + 5], top = -1;
long long int l[MAX_N + 5], r[MAX_N + 5];

int main () {
    long long int n;
    cin >> n;
    for(int i= 1; i <= n; i++) cin >> a[i];
    //设置两个边界
    a[0] = a[n + 1] = -1;
    s[top = 0] = 0;
    for(int i = 1; i <= n; i++) {
        while(a[s[top]] >= a[i]) top--;
        l[i] = s[top];//比第i快左边矮的木块
        s[++top] = i;
    }
    s[top = 0] = n + 1;
    for(int i = n; i >= 1; i--) {
        while(a[s[top]] >= a[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long long int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, a[i] * (r[i] - l[i] - 1));
    }
    cout << ans << endl;
    return 0;
}
