/*************************************************************************
	> File Name: EP01.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 14时56分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int is_val(int n) {
    if(n % 3 == 0 || n % 5 == 0) {
        return n;
    }
    return 0;
}

int main() {
    int sum = 0;
    for(int i = 1; i < 1000; i++) {
       sum += is_val(i);
    }
    printf("%d", sum);
    return 0;
}
