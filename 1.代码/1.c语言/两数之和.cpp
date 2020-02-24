/*************************************************************************
	> File Name: 两数之和.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月21日 星期五 15时16分04秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

int main() {
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        int s;
        scanf("%d", &s);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j] == s - a[i]) {
                 printf("%d %d", i + 1, j + 1);
                break;
            }       
        }   
            
    }
    return 0;
}

