/*************************************************************************
	> File Name: OJ190.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月21日 星期六 20时03分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 8000000

int prime[N + 5] = {0};
int is_prime[N + 5] = {1, 1, 0};
void init(int n) {
    for(int i = 2; i * 2 <= n; i++) {
        if(!is_prime[i]) prime[++prime[0]] = i;
        for(int j = i; j <= prime[0]; j++) {
            if(prime[j] * i > N) break;
            is_prime[prime[j] * i] = 1;
            if(i % prime[j]) break;
        }
    }
    return ;
}
void solve(int n) {
    int ans = 0;
    for(int i = 2; i * 2 <= 0; i++) {
        if(!is_prime[i] && !is_prime)
    } 
}

int main () {
    int init();
    int n;
    while(cin >> n) solve(n);
    return 0;
}
