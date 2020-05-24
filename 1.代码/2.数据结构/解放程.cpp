/*************************************************************************
	> File Name: 解放程.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月23日 星期六 17时28分04秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>
double func(double x) {
    return pow(x, 4) + 5 * pow(x, 3) + 6 * x * x + 7 * x + 4;
}
double solve_equation(double y) {
    double l = 0, r = 100, mid;
    double x;
    while (l < r) {
        mid = (l + r) / 2;
        double tmp = func(mid);
        if (fabs(tmp - y) < 0.00001) return mid;
        else if (tmp > y) r = mid;
        else l = mid;
    }
    return -1;

}
int main() {
    double y;
    scanf("%lf", &y);
    printf("%.10f\n", solve_equation(y));
}
