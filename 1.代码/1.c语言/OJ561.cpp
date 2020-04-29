/*************************************************************************
	> File Name: OJ561.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月29日 星期三 19时11分36秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

int empty, full, n, w[505], val[505], ans[10005];

int main () {
    memset(ans, 0x3F, sizeof(ans));
    ans[0] = 0;
    cin >> empty >> full >> n;
    full -= empty;
    for(int i = 1; i <= n; i++) {
        cin >> val[i] >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = w[i]; j <= full; j++) {
            ans[j] = min(ans[j], ans[j - w[i]] + val[i]);
        }   
    }
    if(ans[full] == 0x3F3F3F3F) {
        cout << "This is impossible." << endl;
    } else {
        cout << "The minimum amount of money in the piggy-bank is " << ans[full] << ".\n";
    }
    return 0;
}
