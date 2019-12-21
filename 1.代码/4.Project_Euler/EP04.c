/*************************************************************************
	> File Name: EP04.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 18时08分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int is_val (int n) {
    int x = n, temp = 0;
    while(x) {
        temp = temp * 10 + x % 10;
        x /= 10;
    }
    return temp == n;
}

int main() {
    int ans = 0;
    for(int i = 100; i < 1000; i++) {
        for(int j = i; j < 1000l; j++) {
            if(is_val(i * j) && i * j > ans) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
