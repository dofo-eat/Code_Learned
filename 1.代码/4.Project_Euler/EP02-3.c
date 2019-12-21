/*************************************************************************
	> File Name: EP02-3.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 16时00分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 4000000
int main() {
    int fib[3] = {0, 1};
    int sum = 0, n = 2;
    while(fib[(n - 1) % 3] + fib[(n - 2) % 3] <= N) {
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if(!(fib[(n % 3)] & 1)) sum += fib[n % 3];
        n += 1;
    }
    printf("%d", sum);
    return 0;
}
