/*************************************************************************
	> File Name: OJ111.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 20时21分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    double n;
    scanf("%lf", &n);
    if(n <= 3) {
        printf("14");
    }else {
        printf("%.1f", 14 + (n - 3) * 2.3);
    }
    return 0;
}
