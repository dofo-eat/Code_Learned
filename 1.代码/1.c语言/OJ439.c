/*************************************************************************
	> File Name: OJ439.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月30日 星期六 20时16分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    double x;
    scanf("%lf",&x);
    int n = 0;
    double sum = 0, v = 2;
    while(x - sum > 0){
        sum += v;
        v *= 0.98;
        n++;
    }
    printf("%d", n);
    return 0;
}
