/*************************************************************************
	> File Name: OJ176.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月16日 星期六 17时48分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    char a[1001];
    char b[1001];
    int sum = 0;
    scanf("%[^\n]s", a);
    getchar();
    scanf("%[^\n]s", b);
    char *temp = strstr(a,b);
    while(temp != NULL) {
        sum++;
        temp = strstr(temp + 1,b);
    }
    printf("%d",sum);
    return 0;
}
