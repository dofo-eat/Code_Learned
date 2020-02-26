/*************************************************************************
	> File Name: EP31-3.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 15时43分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 8
#define M 200

int w[N + 5] = {1, 2, 5, 10, 20,50, 100, 200};
int f[M + 5] = {0};

int main() {
    f[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= M; j++) {
            if(j >= w[i])
            f[j] += f[j - w[i]];
        }
    }
    printf("%d\n",f[M]);
    return 0;
}
