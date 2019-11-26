/*************************************************************************
	> File Name: OJ136.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月08日 星期五 18时47分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[10001];
    for(int i = 1; i <= n; i++) {
        if(i % 7 == 0){
            arr[++arr[0]] = i;
        }
    }
    for(int i = 1; i <= arr[0]; i++) {
        printf("%d\n",arr[i]);
    }
    return 0;
}
