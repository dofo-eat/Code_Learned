/*************************************************************************
	> File Name: OJ148.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月12日 星期二 18时33分15秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int n = 50;
    char a[n];
    char b[50] = {0};
    int j = 0;
    scanf("%s", a);
    for(int i = strlen(a) - 1; i >= 0; i--) {
        b[j] = a[i];
        j++;
    }
    printf("%s",b);
    return 0;
}
