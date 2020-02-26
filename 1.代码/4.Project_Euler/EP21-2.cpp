/*************************************************************************
	> File Name: EP21-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月29日 星期日 19时14分58秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define N 4000000

int f[N + 5] = {0};
int prime[N + 5] = {0};
int cnt[N + 5] = {0};

void init() {
    for(int i = 2; i <= N; i++) {
        if(!prime[i]){
            prime[++prime[0]] = i;
            f[i] = i + 1;
            cnt[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > N) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                f[i * prime[j]] = f[i] /(pow(prime[j],cnt[i] + 1) - 1) *( pow(prime[j], cnt[i] + 2) - 1);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
    return ;
}

int main() {
    long long sum = 0;
    init();
    for(int i = 2; i <= N; i++) {
        f[i] -= i;
    }
    for(int i = 2; i <= N; i++) {
        if(f[i] != i && f[i] < N &&f[f[i]] == i) sum += i;
    }
    cout << sum << endl;
    return 0;
}
