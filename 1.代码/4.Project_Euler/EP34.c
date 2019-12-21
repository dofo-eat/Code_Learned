/*************************************************************************
	> File Name: EP34.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 20时03分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 2903040
int keep[10] = {0};

/*void fac() {
    for(int i = 2; i <= 9; i++) {
    keep[i] = i * keep[i - 1];
    }
    return ;
 }*/
//速度更快一些

int fib(int n) {
    if(keep[n]) return keep[n];
    if(n == 0) return 1;
    if(n == 1) return 1;
    else return keep[n] = n * fib(n - 1);
}  

long long int is_val(long long int n) {
    long long int x = n;
    long long int temp = 0;
    while(x) {
        temp +=  fib(x % 10);
        x /= 10;
    }
    return temp == n;
}

int main() {
    long long int sum = 0;
    for(long long int i = 3; i < N; i++) {
        if(is_val(i)) sum += i;
    }
    printf("%lld\n", sum);
    return 0;
}
