/*************************************************************************
	> File Name: EP02-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 15时52分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 4000000

int main() {
    int a = 0, b = 1, c;
    int sum = 0, n = 0;
    while(a + b <= N) {
        n += 1;
        b = a + b;
        a = b - a;
        if(b & 1) continue;
        sum += b;
    }
    printf("%d\n", sum);
    return 0;
}
