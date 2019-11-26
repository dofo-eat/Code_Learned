/*************************************************************************
	> File Name: OJ177.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月16日 星期六 18时55分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char a[27] = {0};
    scanf("%[^\n]", a);
    char b[27] = {0};
    printf("%s\n",a);
    int len = strlen(a) - 1;
    while(len--) {
        b[0] = a[strlen(a) - 2];
        b[1] = a[strlen(a) - 1];
        for(int i = 0; i < strlen(a) - 2; i++){
            b[i + 2] = a[i];
        }
        printf("%s\n",b);
        strcpy(a,b);
    }
    return 0;
} 
