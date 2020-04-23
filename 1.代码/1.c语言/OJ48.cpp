/*************************************************************************
	> File Name: OJ48.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月22日 星期三 20时57分14秒
 ************************************************************************/
#include<iostream>
using namespace std;

int all, n, w[10005], v[10005],ans[10005]; //all总重量

int main () {
    cin >> all >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= all; j++) {
            if(j >= w[i]) {
                ans[j] = max(ans[j], ans[j -w[i]] + v[i]);
            } 
        }
    }
    cout << ans[all] << endl;
    return 0;
}

