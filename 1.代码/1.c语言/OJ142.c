/*************************************************************************
	> File Name: OJ142.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月10日 星期日 14时40分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int pc(int n) {
    int c = 0, temp = n;
    while(n) {
        c = c * 10 + n % 10;
        n /= 10;
    }
    return temp == c;
}
int is_prime(int n) {
    for(int j = 2; j < n; j++){
        if(n % j == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int c = 0;
    int a, b;
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++) { 
        if(pc(i) && is_prime(i)) {
            if(c == 1) {
                printf(" ");
            }
            printf("%d", i);
            c = 1;
        }
    }
    return 0;
}
