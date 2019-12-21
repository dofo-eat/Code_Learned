/*************************************************************************
	> File Name: EP07.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月17日 星期二 18时44分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int is_val(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int i, cnt;
    for(i = 2, cnt = 0; cnt < 10001; i++) {
        if(is_val(i)) cnt += 1;
    }
    printf("%d\n", i - 1);
    return 0;
}
