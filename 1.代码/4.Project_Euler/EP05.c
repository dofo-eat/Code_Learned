/*************************************************************************
	> File Name: EP05.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月17日 星期二 18时23分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int gcd (int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
   int ans = 1;
    for(int i = 1; i <= 20; i++) {
        if(ans % i == 0) continue;
        ans *= i / gcd(ans, i);// 最小公倍数的公式 lcm = (a * b) / gcd(a, b);
    }
    printf("%d\n", ans);
    return 0;
}
