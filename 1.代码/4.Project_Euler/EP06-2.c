/*************************************************************************
	> File Name: EP06-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 18时34分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int sum1 = 5050;
    int sum2 = (2 *(100 * 100 * 100) + 3 * (100 * 100) + 100) / 6;
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;
}
