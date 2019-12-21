/*************************************************************************
	> File Name: EP36.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 20时48分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000000

int erjin(int n) {
    int x = n;
    int temp = 0;
    while(x) {
        temp = temp * 2 + x % 2;
        x /= 2;
    }
    return temp == n;
}

int is_val(int n) {
    int x = n;
    int temp = 0;
    while(x) {
        temp =  temp * 10 + x % 10;
        x /= 10;
    }
    return temp == n;
}

int main() {
    int sum = 0;
    for(int i = 1; i < N; i++) {
        if(is_val(i) && erjin(i)) sum += i;
    }
    printf("%d\n",sum);
    return 0;
}
