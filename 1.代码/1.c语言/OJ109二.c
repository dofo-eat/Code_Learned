/*************************************************************************
	> File Name: OJ109二.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 19时59分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int flag = 0;
    scanf("%d", &n);
    while (n && flag != 0) {
        n % 10 & 1 ? n / 10 : (flag = 1);
    }
    if(flag == 1) {
        printf("YES");
    }else {
        printf("NO");
    }
    return 0;
}
