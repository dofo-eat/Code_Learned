/*************************************************************************
	> File Name: OJ117二.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月06日 星期三 20时02分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int a;
    scanf("%d", &a);
    int b = a; 
    int c = 0;
    while(a) {
        c = c * 10 + a % 10;
        a /= 10;
    }
    if(b == c ){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
