/*************************************************************************
	> File Name: Oj114.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 20时46分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    char x;
    scanf("%c", &x);
    if(x == 'h') {
        printf("He");
    }else if(x == 'l') {
        printf("Li");
    }else if(x == 'c') {
        printf("Cao");
    }else if(x == 'd') {
        printf("Duan");
    }else if(x == 'w') {
        printf("Wang");
    }else{
        printf("Not Here");
    }
    return 0;
}
