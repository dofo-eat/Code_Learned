/*************************************************************************
	> File Name: OJ140.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月10日 星期日 12时28分48秒
 ************************************************************************/


/*************************************************************************
	> File Name: OJ140.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月10日 星期日 12时28分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char c = 'A';
    for(int i = 1; i <= n - 1; i++) {
        for(int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for(int j = 0; j < 2 * i - 1; j++){
            printf("%c", c);
        }
        printf("\n");
        c++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++) {
            printf(" ");
        }
        for(int j = 0; j <  2 * n  - 1 - 2 * i; j++) {
            printf("%C",c);
        }
        printf("\n");
        c--;
    }
    return 0;
}


