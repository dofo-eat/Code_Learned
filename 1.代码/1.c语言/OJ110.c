/*************************************************************************
	> File Name: OJ110.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 20时16分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    double x;
    scanf("%lf", &x);
    if(x <= 15) {
        printf("%.2f", x * 6.0);
    }else {
        printf("%.2f", 15 * 6.0 + (x - 15) * 9.0);
    }
    return 0;
}
