/*************************************************************************
	> File Name: 矩阵旋转输出.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月01日 星期五 18时59分21秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int matrix[100][100];
    int m;
    int n;
    int flag;
    int i, j;
    scanf("%d %d", &m, &n);
	for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
             scanf("%d", &matrix[i][j]);
        }
    }
    scanf("%d",&flag);
    int change;
  	if(flag ==1) {
    	for(i = 0; i < m; i++) {
            for(j = 0; j < n / 2; j++) {
                change = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = change;
            }
        }
    }
    else {
        for(i = 0; i < m / 2; i++) {
            for(j = 0; j < n; j++) {
                change = matrix[i][j];
                matrix[i][j] = matrix[m - i - 1][j];
            	matrix[m - i - 1][j] = change;
            }
        }
    }
    for(i = 0; i < m; i ++){
        for(j = 0; j < n; j++){
            printf("%d", matrix[i][j]);
            j < n - 1 && printf(" ");
        }
        printf("\n");
    }
    return 0;
}
