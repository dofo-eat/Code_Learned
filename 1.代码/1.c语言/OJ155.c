/*************************************************************************
	> File Name: OJ155.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月13日 星期三 18时26分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int m = 3;
    int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        m += i * 2;
        printf("%d\n", m);
        sum += m;
    }
    printf("%d", sum);
    return 0;
}
