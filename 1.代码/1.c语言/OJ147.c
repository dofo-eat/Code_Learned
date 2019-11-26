/*************************************************************************
	> File Name: OJ147.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月12日 星期二 18时08分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    int n = 10001;
    char a[n];
    scanf("%s", a);
    if((a[strlen(a) - 1] - 48) % 2 == 0) {
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
