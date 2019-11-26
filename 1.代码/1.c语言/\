/*************************************************************************
	> File Name: OJ143.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月10日 星期日 18时09分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int prime(int x) {
    int n;
    n = (x / 1000 % 10) * 10 + (x / 100 % 10);
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int sqare(int y) {
    int m;
    m = (y / 10 % 10) * 10 + (y % 10);
    for(int i = 0; i * i <= m; i++) {
        if(i * i == m) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int a,b;
    int flag = 0;
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++) {
        if(i % 6 == 0 && prime(i) && sqare(i)) {
            if(flag == 0) {
                printf("%d",i);
            } else {
                printf(" %d", i);
            }
            flag++;
        }
    }
    printf("\n%d", flag);
    return 0;
}
