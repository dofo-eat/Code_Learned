/*************************************************************************
	> File Name: switch语句的使用.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月03日 星期二 19时28分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n;
    scanf("%d", &n);
    switch(n) {
        case 1: printf("one two three");   break;
        case 2: printf("two three");   break;
        case 3: printf("three"); break;
        default:printf("error");
    }
    return 0;
}
