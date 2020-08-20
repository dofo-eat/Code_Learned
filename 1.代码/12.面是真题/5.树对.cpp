/*************************************************************************
	> File Name: 5.树对.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月19日 星期三 16时42分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, k, ans;

int main() {
    cin >> n >> k;
    if(k == 0) {
        cout << n * n << endl;
        return 0;
    }
    for(int y = k + 1; y <= n; y++) {
        int t1 = n / y, t2 = n % y;
        ans += t1 * (y - k);
        ans += t2 - k + 1 > 0 ? t2 - k + 1 : 0;
    } 
    cout << ans << endl;
    return 0;
}
