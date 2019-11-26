/*************************************************************************
	> File Name: OJ115.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 21时00分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x == y) {
        printf("100");
    }else if(x / 10 == y % 10 && x % 10 == y /10) {
        printf("20");
    }else if((x / 10 == y /10 || x / 10 == y % 10 ) || (x % 10 == y % 10 || y % 10 == y /10)){
        printf("2");
    }else {
        printf("0");
    }
    return 0;
}
