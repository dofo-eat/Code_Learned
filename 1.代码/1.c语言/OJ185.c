/*************************************************************************
	> File Name: OJ185.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 16时03分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int fib(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
int main() {
    int n;
    scanf("%d", &n);
    int sum = fib(n);
    printf("%d", sum);
    return 0;
}
