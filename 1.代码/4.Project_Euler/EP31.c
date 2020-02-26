/*************************************************************************
	> File Name: EP31.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 14时45分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 8
#define M 200

int f[N + 5][M + 5];
int w[N + 5] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
    for(int i = 0; i < N;i++) {
        f[i][0] = 1;
        for(int j = 1; j <= M; j++) {
            f[i][j] = 0;
            if(i >= 1) f[i][j] += f[i - 1][j];
            if(j >= w[i]) f[i][j] += f[i][j - w[i]];
            //拼凑第I中硬币J元钱W『I』是第I元钱的面值
        }
    }
    printf("%d\n", f[N - 1][M]);
    return 0;
}
