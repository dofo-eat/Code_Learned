/*************************************************************************
	> File Name: OJ2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月02日 星期六 00时39分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int grade;
    scanf("%d",&grade);
    if(grade >= 0 && grade < 60) {
        printf("D");
    }else if(grade >= 60 && grade <75) {
        printf("C");
    }else if(grade >= 75 && grade < 85) {
        printf("B");
    }else{
        printf("A");
    }
    return 0;
}
