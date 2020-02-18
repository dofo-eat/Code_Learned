/*************************************************************************
	> File Name: OJ310-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月28日 星期六 14时42分45秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 1000000

int prime[N + 5] = {0};
int cnt[N + 5] = {0};

void init(int n) {
    for(int i = 2; i <= n; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

/*int main () {
    int n;
    cin >> n;
    init(n);
    for(int i = 2; i <= n; i++) {
        int temp = i;
        for(int j = 1; j <= prime[0] &&temp >= prime[j]; j++) {
            while(temp % prime[j] == 0)
            temp /= prime[j], cnt[prime[j]]++;
        }
    }
    for(int i = 1; i <= prime[0]; i++) {
       if(!cnt[prime[i]]) continue;
        cout << prime[i] << " " << cnt[prime[i]] << endl;
    }
    return 0;
}*/
int main () {
    int n;
    cin >> n;
    init(n);
    for(int j = 1; j <= prime[0]; j++) {
        long long int tmp = prime[j], cnt = 0;
        while(tmp <= n) {
            cnt += n / tmp;
            tmp *= prime[j];
        }
        cout << prime[j] << " " << cnt << endl;
    }
    return 0;
}
