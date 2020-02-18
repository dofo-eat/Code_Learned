/*************************************************************************
	> File Name: 如何计算平方根.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年01月07日 星期二 19时17分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define EPS 1e-7

double my_sqrt(double x) {
    double l = 0, r = (x <= 1.0 ? 1.0 : x);
    while(r - l > EPS) {
        double mid = (l + r) / 2.0;
        if(mid * mid <= x) l = mid;
        else r = mid;
    }
    return l;
}

/*double my_sqrt(double x) {
    double l = 0, r = (x <= 1.0? 1.0:x);
    for(int i = 0; i <= 10000; i++) {
        double mid = (l + r) / 2.0;
        if(mid * mid <= x) l = mid;
        else r = mid;
    }
    return l;
}
*/
int main () {
    double x;
    scanf("%lf", &x);
    printf("%lf\n",my_sqrt(x));
    return 0;
}
