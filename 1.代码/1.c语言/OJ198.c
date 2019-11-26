/*************************************************************************
	> File Name: OJ198.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月20日 星期三 20时58分37秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
long long int a[1000000];
long long int fib(long long int n) {
    if (a[n] != 0) return a[n];
    if(n == 1) return 1;
    if(n == 2) return 1;
    a[n] = (fib(n - 1) % 1000000007 + fib(n - 2) % 1000000007) % 1000000007;
    return a[n];
}
int main() {
    long long int n;
    scanf("%lld", &n);
    printf("%lld", fib(n));
    return 0;
}

