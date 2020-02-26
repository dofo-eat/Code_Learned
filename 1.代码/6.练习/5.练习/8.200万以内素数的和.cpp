/*************************************************************************
	> File Name: 8.200万以内素数的和.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月26日 星期四 16时53分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 2000000

int prime[N + 5] = {0};

/*void init() {
    for(int i = 2; i <= N; i++) {
        if(prime[i]) continue;
        prime[++prime[0]] = i;
        for(int j = i; j <= N; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}*/
void inint() {
    for(int i = 2; i <= N; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > N) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int main () {
    inint();
    long long int sum = 0;
    for(long long int i = 1; i <= prime[0]; i++) {
        sum += prime[i];
    }
    cout << sum << endl;
    return 0;
}
