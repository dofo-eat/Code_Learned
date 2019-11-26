/*************************************************************************
	> File Name: OJ108.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 13时17分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    char s1;
    scanf("%c", &s1);
    double m, n;
    scanf("%lf %lf", &m, &n);
    if(s1 == 'r') {
        printf("%.2f", m * n);
    }else{
        printf("%.2f", (m * n) / 2);
    }
    return 0;
}
