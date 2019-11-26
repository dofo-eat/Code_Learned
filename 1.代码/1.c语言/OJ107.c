/*************************************************************************
	> File Name: OJ107.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 13时13分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n % 7 == 0 && n % 2 != 0) {
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
