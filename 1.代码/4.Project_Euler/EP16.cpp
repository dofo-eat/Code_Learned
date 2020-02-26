/*************************************************************************
	> File Name: EP16.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月28日 星期六 15时51分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 450

int ans[N + 5] = {1, 1, 0};

int main () {
    for(int i = 0; i < 1000; i++) {
        for(int j = 1; j <= ans[0]; j++) ans[j] *= 2;
        for(int j = 1; j <= ans[0]; j++) {
            if(ans[j] <  10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (ans[0] == j);
        }
    }
    int sum = 0;
    for(int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}
