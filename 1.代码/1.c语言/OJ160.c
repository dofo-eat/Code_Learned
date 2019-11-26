/*************************************************************************
	> File Name: OJ160.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月13日 星期三 19时07分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14

int main() {
    double r, h;
    scanf("%lf %lf", &r, &h);
    double s, v;
    s = PI * r * r + 4.0 * r * r + (PI * r + 2.0 * r + r * 2 *sqrt(2)) * h;
    v = (PI * r * r + 4 * r * r) / 2.0 * h;
    printf("%.2f", s);
    return 0;
}
