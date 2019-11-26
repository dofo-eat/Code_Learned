/*************************************************************************
	> File Name: OJ161.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月13日 星期三 19时52分18秒
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

    printf("%.6f",sum);
    return 0;
}

