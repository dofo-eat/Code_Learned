/*************************************************************************
	> File Name: OJ464.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月19日 星期二 17时18分09秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int main() {
    int x, y;
    int sum = 0;
    scanf("%d %d", &x, &y);
    for(int i = x; i <= y; i++) {
        if((i % 100 != 0 && i % 4 == 0) || i % 400 == 0) 
        sum++;
    }
    printf("%d", sum);
    return 0;
}
