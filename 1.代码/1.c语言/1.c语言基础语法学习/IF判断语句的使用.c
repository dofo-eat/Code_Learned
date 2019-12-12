/*************************************************************************
	> File Name: IF判断语句的使用.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月03日 星期二 19时06分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n == 0) printf("FOOLISH");
    else if (n < 60) printf("FAIL");
    else if (n < 75) printf("MEDIUM");
    else printf("GOOD");
    return 0;
}
