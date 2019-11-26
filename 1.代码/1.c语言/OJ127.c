/*************************************************************************
	> File Name: OJ127.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月07日 星期四 20时22分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    double sum = 0;
    sum = x;
    while(n--){
        sum = sum * (1.06);
    }

    printf("%d",(int)sum);
    return 0;
}
