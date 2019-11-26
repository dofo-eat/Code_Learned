/*************************************************************************
	> File Name: OJ134.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月08日 星期五 17时26分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int a, b, i = 0;
    int arr[10001];
    scanf("%d %d", &a, &b);
    for(i = 1; i * 11 <= b; i++) {
        (11 * i >= a) && (printf("%d", i * 11), break, 1);
    }
    for(; i * 11 <= b; i++) {
        (11 * i >= a) && (printf("%d ", i * 11));
    }
    return 0;
}
