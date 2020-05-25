/*************************************************************************
	> File Name: 10.test.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月24日 星期日 19时38分31秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 500
int ans[N + 5] = {0};

void solve(long long a, long long b, long long p) {
    int ans[N + 5] = {0};
    ans[0] = 1, ans[1] = 1;
    for(int i = 0; i < b; i++) {
        for(int j = 1; j <= ans[0]; j++) {
            ans[j] *= a;
        }
        for(int k = 1; k <= ans[0]; k++) {
            if(ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (ans[0] == k);
        }
    }
    long long sum = 0;
    for(int i = ans[0]; i > 0; i--) {
        sum = sum * 10 + ans[i];
    }
    sum = sum % p;
    printf("%lld", sum);
    printf("\n");
}

int main() {
    long long  a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);
    solve(a, b, p);
    long long sum = 0;
    
    return 0;
}

