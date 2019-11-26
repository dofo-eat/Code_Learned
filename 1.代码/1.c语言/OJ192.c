/*************************************************************************
	> File Name: OJ192.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月20日 星期三 19时31分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double find(long long int n) {
    double l = 0, r = 30;
    double mid;
    while(r - l > 1e-6) {
        mid = (l + r) / 2.0;
        if(exp(mid) * mid > n) {
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return mid;
}
int main() {
    long long int a;
    scanf("%lld", &a);
    printf("%.4f",(double)find(a));
    return 0;
}
