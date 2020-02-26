/*************************************************************************
	> File Name: EP39.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月29日 星期日 15时09分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 1000

int cnt[N + 5] = {0};

int gcd(int a, int b) {
    return(b? gcd(b, a % b) : a);
}

int main () {
    for(int n = 1; n <= 32; n++) {
        for(int m = n + 1; m <= 32; m++) {
            if(gcd(m,n) - 1) continue;
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;
            for(int p = a + b + c; p <= 1000; p += (a + b + c)) {
                cnt[p] += 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(cnt[i] > cnt[ans]) ans = i;
    }
    cout << ans << endl;
    return 0;
}
