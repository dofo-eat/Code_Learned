/*************************************************************************
	> File Name: 牛顿迭代法计算平方根.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年01月07日 星期二 19时36分43秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define EPS 1e-7

double f(double x, double n) {
    return x * x - n;
}

double f_prime(double x) {
    return 2 * x;
}

double my_sqrt(double n) {
    double x = 1.0;
    int cnt = 0;
    while(fabs(f(x, n)) > EPS) {
        x = x - f(x, n) / f_prime(x);
        cnt += 1;
    }
    printf("run %d steps\n", cnt);
    return x;
}

int main () {
    double x;
    scanf("%lf", &x);
    printf("%lf\n", my_sqrt(x));
    return 0;
}
