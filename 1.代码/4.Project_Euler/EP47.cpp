/*************************************************************************
	> File Name: EP47.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月29日 星期日 18时05分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 1000000

int prime[N + 5] = {0};

void init() {
    for(int i = 2; i <= N; i++) {
        if(prime[i]) continue;
        for(int j = i; j <= N; j += i) {
            prime[j] += 1;
        }
    }
    return ;
}

int main () {
    init();
    int ans = 0;
    for(int i = 1000; i < N; i++) {
        int flag = 1;
        for(int j = 0; j < 4 && flag;j++) {
            flag = (prime[i + j] == 4);//有四个素因子
        }
        if(!flag) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}
