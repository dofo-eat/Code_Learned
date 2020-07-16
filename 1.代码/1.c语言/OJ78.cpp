/*************************************************************************
	> File Name: OJ78.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月16日 星期四 13时15分51秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

int a[2005], b[2005];
int ans[2020];

int main() {
    char n[2005], m[2005];
    cin >> n >> m;
    int len1 = strlen(n);
    int len2 = strlen(m);
    int max = 0;
    if(len1 >= len2) {
        max = len1;
    }
    else{
        max = len2;
    }
    for(int i = len1 - 1, j = 1; i >= 0;i--, j++) {
        a[j] = n[i] - '0';
    }
    for(int i = len2 - 1, j = 1; i >= 0;i--, j++) {
        b[j] = m[i] - '0';
    }
    ans[0] = 1, ans[1] = 1;
    for(int i = 1; i <= max; i++) {
        ans[i] = a[i] + b[i];
        ans[0]++;
    }
    for(int i = 1; i <= max + 2; i++) {
        if(ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    int i = 0;
    if(ans[ans[0]] == 0) i = ans[0]-1;
    else i = ans[0];
    for(; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
