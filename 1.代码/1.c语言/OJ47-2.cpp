/*************************************************************************
	> File Name: OJ47-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月22日 星期三 20时45分18秒
 ************************************************************************/
#include<iostream>
using namespace std;
//0背包优化解决大数据
int all, n, w[105], v[105],ans[10005]; //all总重量

int main () {
    cin >> all >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = all; j > 0; j--) {
            if(j <= w[i]) {
               // ans[j] = ans[j];
                break;
            } else {
                ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
            }
        }
    }
    cout << ans[all] << endl;
    return 0;
}

