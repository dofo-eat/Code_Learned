/*************************************************************************
	> File Name: EP30.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 19时47分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max_n 354294
#include<math.h>

int is_val(int n) {
    int x = n;
    int temp = 0;
    while(x) {
        temp += (int)pow(x % 10, 5);
        x /= 10;
    }
    return temp == n;
}

int main() {
    int sum = 0;
    for(int i = 2; i < max_n; i++) {
        if(is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
