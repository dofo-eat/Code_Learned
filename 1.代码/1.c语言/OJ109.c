/*************************************************************************
	> File Name: OJ109.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 18时50分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, i = 0, m = 0;
    int flag = 0;
    int a[10];
    scanf("%d", &n);
    while (n) {
        m = n % 10;
        n /= 10;
        a[i] = m;
        i++;
    }
    for(int j = 0; j < i; j++) {
        if(a[j] % 2 == 0) {
            printf("YES");
            flag = 1;
            break;
        }
    }
    if(flag = 0) {
        printf("NO");
    }
    return 0;
}
