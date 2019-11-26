/*************************************************************************
	> File Name: OJ164.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月13日 星期三 20时39分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n % m == 0) {
        printf("%d", n / m);
    }else{
        printf("%d", n / m + 1);
    }
    return 0;
}
