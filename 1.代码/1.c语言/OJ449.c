/*************************************************************************
	> File Name: OJ449.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月06日 星期五 17时50分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[21][21] = {0};
    for(int i = 0; i < n; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for(int i = 2; i < n; i++) {
        for(int j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            (j > 0 && j < n) && printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
