/*************************************************************************
	> File Name: 3.安置路灯.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月19日 星期三 16时21分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int t, ans = 0;
        string s;
        cin >> t >> s;
        for(int i = 0; i < t; i++) {
            if(s[i] == '.') {
                ans++;
                i += 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
