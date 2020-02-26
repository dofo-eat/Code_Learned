/*************************************************************************
	> File Name: EP31-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 15时06分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 8
#define M 200

int w[N + 5] = {1, 2, 5, 10, 20, 50, 100, 200};
int f[2][M + 5];

int main() {
    for(int k = 0; k < N; k++) {
        int i = k % 2;
        f[i][0] = 1;
        for(int j = 1; j <= M; j++) {
            f[i][j] = 0;
            f[i][j] += f[i ^ 1][j];
            if(j >= w[k]) f[i][j] += f[i][j - w[k]];
        }
    }
    printf("%d\n", f[(N - 1) % 2][M]);
    return 0;
}
