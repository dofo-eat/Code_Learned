/*************************************************************************
	> File Name: OJ118.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月06日 星期三 13时56分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    char a[12][12] = {"rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig"};
    int year1 = 1900;
    int year;
    scanf("%d", &year);
    int n;
    n = (year - year1) % 12;
    if(n < 0) {
        n = n + 12;
    }
    printf("%s",a[n]);
    return 0;
}
