/*************************************************************************
	> File Name: 11.扩展欧几里得.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月07日 星期六 20时10分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int ex_gcd(int a, int b, int *x, int *y) {
    if(!b) {
        *x = 1, *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    xx = *y;
    yy = *x - a / b * xx;
    return ret;
}

int main() {
    int a, b, x, y;
    while(~scanf("%d %d", &a, &b)) {
        printf("gcd(%d %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a,x, b, y, a * x + b * y);
    }
    return 0;
}
