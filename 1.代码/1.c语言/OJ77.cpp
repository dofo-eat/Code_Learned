/*************************************************************************
	> File Name: OJ77.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月14日 星期二 16时57分01秒
 ************************************************************************/
#include<iostream>
#include <cstring>
using namespace std;

int ans[2000];

void solve (int a, int b) {
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 1; i <= b; i++) {
        for(int j = 1; j <= ans[0]; j++) {
            ans[j] *= a;
        }
        for(int k = 1; k <= ans[0]; k++) {
            if(ans[k] < 10) continue;
            ans[k + 1] += ans[k] /10;
            ans[k] %= 10;
            ans[0] += (ans[0] == k);
        }
    }
    for(int i = ans[0]; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
}
int main() {
    int a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}

