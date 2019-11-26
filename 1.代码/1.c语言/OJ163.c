/*************************************************************************
	> File Name: OJ163.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月13日 星期三 20时34分40秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
int main() {
    double a, b, d;
    scanf("%lf %lf %lf", &a, &b, &d);
    double c;
    c = sqrt(pow(a,2) + pow(b,2) - (2 * a * b * cos(d * PI / 180) ));
    printf("%.6f", c);
    return 0;
}

