/*************************************************************************
	> File Name: OJ126.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月07日 星期四 20时17分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define PI 3.14
int main() {
    double r1, r2;
    scanf("%lf %lf", &r1, &r2);
    printf("%.2f",PI * r1 * r1 - PI * r2 * r2 );
    return 0;
}
