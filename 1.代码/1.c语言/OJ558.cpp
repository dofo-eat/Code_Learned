/*************************************************************************
	> File Name: OJ558.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月29日 星期三 18时07分55秒
 ************************************************************************/

#include<iostream>
using namespace std;

int t, m, mtime[105], mval[105], ans[105][1005];

int main () {
    cin >> t >> m;
    for(int i = 1; i <= m; i++) {
        cin >> mtime[i] >> mval[i];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= t; j++) {
            if(j < mtime[i]) {
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - mtime[i]] + mval[i]);
            }
        }
    }
    cout << ans[m][t] << endl;
    return 0;
}
