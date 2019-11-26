/*************************************************************************
	> File Name: OJ137.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月08日 星期五 19时02分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n; 
    scanf("%d",&n);
    char c = '@';
    for(int i = 0; i <= n; i++){
        for(int j = n - i; j >= 1; j--){
            c = c + 1;
            printf("%c",c);
        }
        printf("\n");
    }
    return 0;
}

