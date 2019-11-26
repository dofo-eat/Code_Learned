/*************************************************************************
	> File Name: OJ144.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月10日 星期日 19时06分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char a[101] = {0};
    scanf("%s", a);
    int b = 0;
    for(int i = 0; i < strlen(a); i++){
        if(a[i] == 'A') {
            b++;
        }
    }
    printf("%d",b);
    return 0;
}

