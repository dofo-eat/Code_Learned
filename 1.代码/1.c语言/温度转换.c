/*************************************************************************
	> File Name: 温度转换.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月03日 星期日 20时14分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    double C;
    scanf("%lf", &C);
    printf("%.2f", 1.8 * C + 32);
    return 0;
}
