/*************************************************************************
	> File Name: OJ149.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月12日 星期二 18时51分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int n = 50;
    char a[n];
    char b[n];
    while(~scanf("%s", a)) {
        strcpy(b,a);
    }
    printf("%ld", strlen(b));
    return 0;
}
