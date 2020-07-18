/*************************************************************************
	> File Name: OJ516-优化.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月18日 星期六 13时51分07秒
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;

long long ans, n, numc[100005], numw[100005];
string str;

int main() {
    cin >> n >> str;
    int cn = 0, wn = 0;
    for (int i = 0, j = str.size() - 1; i < str.size(); i++, j--) {
        if (str[i] == 'C') cn++;
        if (str[j] == 'W') wn++;
        numc[i] = cn;
        numw[j] = wn;
    }
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'O') {
            ans += numc[i] * numw[i];
        }
    }
    cout << ans << endl;
    return 0;
}
