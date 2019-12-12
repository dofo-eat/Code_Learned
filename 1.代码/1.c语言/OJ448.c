/*************************************************************************
	> File Name: OJ448.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月05日 星期四 20时57分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n, m;
    scanf("%d", &n);
    int a[101];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    int flag = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == m){
            printf("%d", i + 1);
            flag = 1;
            break;
        }
    }
    if(flag != 1) printf("0");
    return 0;
}
