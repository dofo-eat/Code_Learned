/*************************************************************************
	> File Name: OJ558.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月29日 星期三 18时07分55秒
 ************************************************************************/

#include<iostream>
using namespace std;

int t, m, mtime[105], mval[105], ans[1005];

int main () {
    cin >> t >> m;
    for(int i = 1; i <= m; i++) {
        cin >> mtime[i] >> mval[i];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = t; j > 0; j--) {
            if(j < mtime[i]) {
                break;
                //ans[i][j] = ans[i - 1][j];
            } else {
                ans[j] = max(ans[j], ans[j - mtime[i]] + mval[i]);
            }
        }
    }
    cout << ans[t] << endl;
    return 0;
}
