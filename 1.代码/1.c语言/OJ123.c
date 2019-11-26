/*************************************************************************
	> File Name: OJ123.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月07日 星期四 19时30分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c, d;
    scanf("%d %d", &c, &d);
    if(c - a >= 0 && b - d >= 0) {
        printf("YES");
    }else if(c - a <= 0 && d - b >= 0) {
        printf("YES");
    }else {
        printf("NO");
    }
    return 0;
}
