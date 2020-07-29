/*************************************************************************
	> File Name: OJ79.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月29日 星期三 13时05分15秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10000000

int prime[MAX_N] = {0};

void init() {
    for(int i = 2; i <= MAX_N; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
    //    cout << prime[i] << endl;

        if(prime[i] >= n && prime[i] <= m) {
            cout << prime[i] << endl;
        }
    }
}
