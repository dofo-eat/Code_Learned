/*************************************************************************
	> File Name: EP08.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月19日 星期四 18时25分33秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define N 1000

char num[N + 5];

int main () {
    long long int len = 0;
    while(cin >> (num + len)) len += strlen(num + len);
    long long int ans = 0, p = 1, zero = 0;
    for(long long int i = 0;num[i]; i++) {
        num[i] -= '0';
        if(num[i]) p *= num[i];
        else zero += 1;
        if(i < 13) continue;
        if(num[i - 13]) p /= num[i - 13];
        else zero -= 1;
        if(zero == 0 && p > ans) ans = p;
    }
    cout << ans<< endl;
    return 0;
}

