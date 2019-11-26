/*************************************************************************
	> File Name: OJ150.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月12日 星期二 19时32分59秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    int i;
    int j;
    int change[201][201];
	for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
            change[j][n - i - 1] = matrix[i][j];
        }
    }
    for(i = 0; i < m;i++) {
        for(j = 0; j < n; j++) {
        	printf("%d",change[i][j]);
            j < n - 1 && printf(" ");
		}
        printf("\n");
    }
    return 0;
}
