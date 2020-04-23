/*************************************************************************
	> File Name: OJ47.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月22日 星期三 20时03分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

int all, n, w[105], v[105],ans[105][10000]; //all总重量

int main () {
    cin >> all >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= all; j++) {
            if(j <= w[i]) {
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], v[i] + ans[ i -1][j - w[i]]);
            }
        }
    }
    cout << ans[n][all] << endl;
    return 0;
}
