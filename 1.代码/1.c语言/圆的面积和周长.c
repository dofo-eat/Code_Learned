/*************************************************************************
	> File Name: 圆的面积和周长.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月03日 星期日 20时04分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define PI 3.14
int main() {
    double r;
    scanf("%lf", &r);
    printf("%.2f\n", 2 * PI * r);
    printf("%.2f\n", r * r * PI);
    return 0;
}
