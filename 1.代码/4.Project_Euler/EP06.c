/*************************************************************************
	> File Name: EP06.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 18时27分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= 100; i++) {
        sum1 += i;
        sum2 += i * i;
    }
    printf("%d",sum1 * sum1 - sum2);
    return 0;
}
