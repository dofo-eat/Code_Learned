/*************************************************************************
	> File Name: OJ438.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月30日 星期六 19时58分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    double n;
    scanf("%lf", &n);
    if(n <= 240) {
        printf("%.1f", n * 0.4783);
    }else if(n >= 241 && n <= 400 ){
        printf("%.1f", 240 * 0.4783 + (n - 240) * 0.5283);
    }else{
        printf("%.1f", 240 * 0.4783 + 160 * 0.5283 + (n - 400) * 0.7783); 
    }
    return 0;
}
