/*************************************************************************
	> File Name: OJ191.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月21日 星期六 20时15分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 80000000

int prime[N + 5] = {0};

void init() {
    for(int i = 2; i <= N; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i >  N) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

void solve(int n, int m) {
    int a = -1, b = -1, c = -1, d = -1;
    int max_len = 0, min_len = N;
    for(int i = 2; i <= prime[0] && prime[i] <= m; i++) {
        if(prime[i - 1] < n) continue;
        int temp = prime[i] - prime[i - 1];
        if(temp < min_len) {
            a = prime[i - 1];
            b = prime[i];
            min_len = temp;
        }
        if(temp > max_len) {
            c = prime[i - 1];
            d = prime[i];
            max_len = temp;
        }
    }
    if(a == -1) {
        cout << "There are no adjacen prime.\n" << endl;
    }
    else {
        cout << a << "," << b << " are closest, " << c << "," << d << " are most distant.";
    }
}
int main () {
    init();
    int n, m;
    while(cin >> n >> m) solve(n, m);

    return 0;
}
