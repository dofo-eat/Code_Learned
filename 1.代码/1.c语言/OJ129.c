/*************************************************************************
	> File Name: OJ129.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月07日 星期四 20时58分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int temp = 100001;
    int a[10001];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] < temp) {
            temp = a[i];
        }else{
            a[i] = temp;
        }
    }
    printf("%d", temp);
    return 0;
}
