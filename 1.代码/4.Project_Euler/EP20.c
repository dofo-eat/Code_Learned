/*************************************************************************
	> File Name: EP20.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 20时41分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 300

int ans[N + 5] = {1, 1, 0};

int main() {
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= ans[0]; j++) {
            ans[j] *= i;
        }
        for(int k = 1; k <= ans[0]; k++) {
            if(ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }
    }
    int sum = 0;
    for(int i = 0; i <= ans[0]; i++) {
        sum += ans[i];
    }
    printf("%d", sum);
    return 0;
}
