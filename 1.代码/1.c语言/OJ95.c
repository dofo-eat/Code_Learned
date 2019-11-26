/*************************************************************************
	> File Name: OJ95.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月03日 星期日 20时22分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum;
    sum = (n % 10) * 10 + (n / 10);
    printf("%d", sum);
    return 0;
}
