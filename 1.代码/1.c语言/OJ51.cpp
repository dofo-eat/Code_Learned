/*************************************************************************
	> File Name: OJ51.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月12日 星期二 20时10分10秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
#define MAX_N 1000

int f[MAX_N + 5];//全白数量
int a[MAX_N + 5];//记录最后一行的数据， 向下数连续白色格子的数量
int s[MAX_N + 5], top = -1;//单调栈

int main () {
    int n, m, ans = 0;
    cin >> n >> m;
    a[m + 1] = -1;
    f[m + 1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1, val; j <= m; j++) {
            cin >> val;//
            if(val == 1) a[j] += 1;
            else a[j] = 0;
        }
        top = -1;
        s[++top] = m + 1;
        for(int j = m; j >= 1; j--) {
            while (a[s[top]] >= a[j]) top--;
            f[j] = (s[top] - j) * a[j] + f[s[top]];
            f[j] %= 100007;
            s[++top] = j;
            ans += f[j];
            ans %= 100007;
        }
    }
    cout << ans << endl;
    return 0;
}
