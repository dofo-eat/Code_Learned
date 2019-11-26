/*************************************************************************
	> File Name: OJ124.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月07日 星期四 19时43分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[4];
    for(int i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
    }
    if(a[1] <= 50 || a[0] >= 1 ) {
        if(a[2] <= 25 || a[3] >= 5) {
            printf("ok");
        }
        else{
            printf("pass");
        }
    }
    else{
        printf("pass");
    }
    return 0;
}
