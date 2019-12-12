/*************************************************************************
	> File Name: OJ205.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月11日 星期三 15时19分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[35][35] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        double sum = 0;
        for(int j = 0; j < m; j++) {
            sum += a[i][j];
        }
        printf("%.6f\n", sum / m);
    }
    return 0;
}
