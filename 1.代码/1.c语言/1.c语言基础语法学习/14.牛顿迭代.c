/*************************************************************************
	> File Name: 14.牛顿迭代.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月10日 星期二 20时20分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define EPLISION 1e-6
double F(double x) {
    return x * x - 2;
}

double f(double x) {
    return 2 * x;
}

double Neton(double (*F)(double), double (*f)(double)) {
    double x = 1.0;
    while(fabs(F(x) > EPLISION)) {
        x -= x - F(x) / f(x);
    }
    return x;
}
int main() {
    double x = Neton(F, f);
    printf("%lf\n", x);
    printf("%lf * %lf - 3 = %lf\n",Neton(F(x), f(x)));
    return 0;
}
