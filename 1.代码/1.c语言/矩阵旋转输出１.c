/*************************************************************************
	> File Name: 矩阵旋转输出１.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月01日 星期五 19时03分15秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int matrix[3][3];
    int i;
    int j;
    int change[3][3];
	for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
            change[j][2 - i] = matrix[i][j];
        }
    }
    for(i = 0; i < 3;i++) {
        for(j = 0; j < 3; j++) {
        	printf("%d",change[i][j]);
            j < 2 && printf(" ");
		}
        printf("\n");
    }
    return 0;
}
