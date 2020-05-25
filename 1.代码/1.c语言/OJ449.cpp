/*************************************************************************
	> File Name: OJ449.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月24日 星期日 18时19分51秒
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

