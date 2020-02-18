/*************************************************************************
	> File Name: OJ471.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月21日 星期六 19时08分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 100

char str_a[N + 5];
char str_b[N + 5];
int a[N + 5], b[N + 5], c[2 * N + 5];

int main() {
    memset(c, 0, sizeof(c));
    scanf("%s %s", &str_a, &str_b);
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    for(int i = 0; i < len_a; i++) a[i] = str_a[len_a - i -1] - '0';
    for(int i = 0; i < len_b; i++) b[i] = str_b[len_b - i -1] - '0';
    for(int i = 0; i < len_a; i++) {
        for(int j = 0; j < len_b; j++) {
            c[i + j] += a[i] * b[j];
            if(c[i + j] < 10) continue;
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }
    int len_c = len_a + len_b;
    while(!c[len_c]) len_c--;
    for(int i = len_c; i >= 0; i--) {
        printf("%d", c[i]);
    }
    printf("\n");
    return 0;
}
