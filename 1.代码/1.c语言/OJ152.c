/*************************************************************************
	> File Name: OJ152.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月12日 星期二 20时47分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char a[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    if(n < 5) {
        printf("%s",a[n + 2]);
    }else{
        printf("%s",a[(n + 2) % 7]);
    }
    return 0;
}
