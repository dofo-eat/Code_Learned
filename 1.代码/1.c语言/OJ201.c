/*************************************************************************
	> File Name: OJ201.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月23日 星期六 13时33分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
int bubble (int b[]) {
    for(int i = 0; i < strlen(b); i++) {
       for(int j = strlen(b) - 1 - j; j >= 0;j++) {
            swap(b[j], b[j + 1]);
        }
    }
}
int main() {
    int n, m = 0;
    scanf("%d", &n);
    int a[n];
    int b[1001] = {0};
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        b[++b[0]] = 1;
    }
    printf("%ld %d", strlen(b), bubble(b));
    return 0;
}
