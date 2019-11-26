/*************************************************************************
	> File Name: OJ106.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月04日 星期一 23时06分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    double n;
    scanf("%lf", &n);
    if(n >= 0) {
        printf("%f",n);
    }else{
        printf("%lf", n * (-1));
    }
    return 0;
}
