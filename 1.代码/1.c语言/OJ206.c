/*************************************************************************
	> File Name: OJ206.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月11日 星期三 15时26分09秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    double a[35][35] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        double sum = 0.0;
        for(int j = 0; j < n; j++) {
            sum += a[j][i];
        }
        printf("%.1f", sum);
        i < m - 1 && printf("\n");
    }
    return 0;
}
