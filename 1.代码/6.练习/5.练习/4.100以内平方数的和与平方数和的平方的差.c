/*************************************************************************
	> File Name: 4.100以内平方数的和与平方数和的平方的差.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月24日 星期二 14时09分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    long long int sum = 0;
    long long int ans = 0;
    
    for(int i = 1; i <= 100; i++) {
        sum += i * i;
        ans += i;
    }
    printf("%d\n", ans * ans - sum);
    return 0;
}
