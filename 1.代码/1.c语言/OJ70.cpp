/*************************************************************************
	> File Name: OJ70.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月19日 星期四 17时15分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

int prime[10000] = {0};

void init(int n) {
    for(int i = 2; i <= n; i++) {
        if(prime[i]) continue;
        for(int j = i; j <= n; j += i) {
            prime[j] = i;
        }

    }
    return ;
}

int main () {
    int n;
    init(1005);
    cin >> n;
    cout << 1 << endl;
    for(int i = 1; i <= n; i++) {
            if(prime[i] == 2 || prime[i] == 3 || prime[i] == 5) {
            cout << i << endl;
        }
    }
    return 0;
}
