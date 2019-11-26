/*************************************************************************
	> File Name: OJ139.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月10日 星期日 10时39分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char c;
    for(int i = 1; i <= n; i++) {
        for(int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for(int j = 0; j < 2 * i; j++){
            c = 'A';
            printf("%c", c);
        }
        printf("\n");
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < i + 1; j++) {
            printf(" ");
        }
        for(int j = 0; j < (n - i - 1) * 2; j++) {
            c = 'A';
            printf("%C",c);
        }
        printf("\n");
    }
    return 0;
}
