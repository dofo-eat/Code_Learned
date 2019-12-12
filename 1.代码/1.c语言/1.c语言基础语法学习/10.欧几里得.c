/*************************************************************************
	> File Name: 10.欧几里得.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月07日 星期六 18时40分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int gcd (int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
int main() {
    int a, b;
    while(~scanf("%d %d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}
