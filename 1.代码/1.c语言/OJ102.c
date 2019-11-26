/*************************************************************************
	> File Name: OJ102.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月04日 星期一 12时06分39秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    double a, b, c, t;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &t);
    printf("%.2f",(1.0 - (1.0 / a + 1.0 / b) * t)) / (1.0 / a + 1. / b - 1.0/ c);
    return 0;
}
