/*************************************************************************
	> File Name: OJ100.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月03日 星期日 20时57分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    double n;
    double sum = 0;
    scanf("%lf", &n);
    for(int i = 0; i < 6; i++) {
        sum = ((n + sum) * (1 + 0.00417));
    }
    printf("$%lf", sum);
    return 0;
}
