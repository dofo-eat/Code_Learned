/*************************************************************************
	> File Name: 第一个没有出现的正数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月21日 星期五 15时23分05秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

int main () {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < n; i++) {
        if(a[i] <= 0 ||a[i] > n){ 
        printf("%d", i + 1);
        break;
        }
    }
    return 0;
}
