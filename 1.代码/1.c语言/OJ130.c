/*************************************************************************
	> File Name: OJ130.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月07日 星期四 21时19分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    double sum = 0;
    while(n--) {
        sum = (m + sum) * 1.00417;
    }
    printf("$%.2f",sum);
    return 0;
}
