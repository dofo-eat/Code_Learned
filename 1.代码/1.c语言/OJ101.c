/*************************************************************************
	> File Name: OJ101.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月04日 星期一 11时56分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, m;
    int sum = 0;
    scanf("%d", &n);
    int a[100000];
    while(n > 0) {
        a[m++] = n % 10;
        n /= 10;
    }
    for(int i = 0; i < m; i++) {
        sum += a[i];
    }
    printf("%d", sum);
    return 0;
}
