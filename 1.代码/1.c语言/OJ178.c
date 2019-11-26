/*************************************************************************
	> File Name: OJ178.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月16日 星期六 19时40分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    int n;
    scanf("%d", &n);
    char str[10] = "A";
    char a[100000], b[100000];
    for (int i = 0; i < n; i++) {
        strcpy(b, a);
        strcat(b, str);
        strcat(b, a);
        strcpy(a, b);
        str[0]++;
    }
    printf("%s", a);
    return 0;
}
