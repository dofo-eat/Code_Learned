/*************************************************************************
	> File Name: OJ98.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月03日 星期日 20时48分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define PI 3.14
int main() {
    double r, h;
    scanf("%lf %lf", &r, &h);
    printf("%.2f\n", PI * r * r);
    printf("%.2f\n",PI * r * r * h);
    return 0;
}
