/*************************************************************************
	> File Name: OJ103.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月04日 星期一 22时56分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a % b == 0) {
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
