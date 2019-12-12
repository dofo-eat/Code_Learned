/*************************************************************************
	> File Name: OJ445.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月05日 星期四 15时23分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[1001];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int temp[1001], m = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0, ans = 0;
        for(int j = 0; j < i; j++) {
            if(a[i] < a[j]) sum++;
        }
        for(int k = i + 1; k < n; k++) {    
            if(a[i] < a[k]) ans++;
        }
        if(sum == ans) m++;
    }
    printf("%d", m);
    return 0;
}
