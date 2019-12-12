/*************************************************************************
	> File Name: 7.递归函数.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月07日 星期六 14时44分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int fac(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n * fac(n - 1);
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        printf("%d",fac(n));
    }
    return 0;
}
