/*************************************************************************
	> File Name: OJ196.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月20日 星期三 20时23分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int LF(int n) {
    int step = 0;
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n == 3) return 1;
    return LF(n - 2) + LF(n - 3);
    
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", LF(n));
    return 0;
}
