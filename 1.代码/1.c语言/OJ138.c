/*************************************************************************
	> File Name: OJ138.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月08日 星期五 21时12分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (n * 2) - (i * 2); j++) {
            c = 'A';
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}
