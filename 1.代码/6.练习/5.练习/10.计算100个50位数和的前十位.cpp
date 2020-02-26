/*************************************************************************
	> File Name: 10.计算100个50位数和的前十位.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月27日 星期五 17时27分14秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define N 52

char str[N + 5] = {0};
int ans[N + 5] = {0};

int main() {
    while(cin >> str) {
        int len = strlen(str);
        if(len > ans[0]) ans[0] = len;
        for(int i = 0; i < len; i++) {
            ans[len - i] += str[i] - '0';
        }
        for(int i = 1; i <= ans[0]; i++) {
            if(ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    for(int i = ans[0]; i > ans[0]- 10; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
