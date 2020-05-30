/*************************************************************************
	> File Name: 18.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月29日 星期五 22时52分04秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
#define MAX_N 1000

int dp[MAX_N + 5][MAX_N + 5];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s1[i -1] != s2[j- 1]) continue;
            dp[i][j] = dp[i - 1][j - 1]+ 1;
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
