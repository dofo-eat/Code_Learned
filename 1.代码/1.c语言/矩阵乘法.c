/*************************************************************************
	> File Name: 矩阵乘法.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月02日 星期六 14时28分47秒
 ************************************************************************/

 #include <stdio.h>

int main() {
    int matrix_a[10][10];
    int matrix_b[10][10];
    int matrix[10][10] = {0};
    int m;
    int n;
    int i, j, k;
    scanf("%d %d",&m, &n);
	for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d",&matrix_a[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d",&matrix_b[i][j]);
        }
    }
    for(i = 0; i < m; i++) {
		for(j = 0; j < m; j++) {
            for(k = 0; k < n; k++) {
				matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < m; j++) {
           printf("%d",matrix[i][j]);
            j < m - 1 && printf(" ");
        }
         printf("\n");
    }
    return 0;
}
