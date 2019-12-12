/*************************************************************************
	> File Name: OJ446.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月05日 星期四 17时17分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[10][10] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n - i; j++) {
            for(int k = i; k < n - i; k++) {
                a[j][k] += 1;
            }
        }        
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", a[i][j]);
            j < n - 1 && printf(" ");
        }
        printf("\n");
    }
    return 0;
}
