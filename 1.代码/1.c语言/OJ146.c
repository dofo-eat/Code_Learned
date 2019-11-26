/*************************************************************************
	> File Name: OJ146.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月10日 星期日 20时24分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char a[50] = {0};
    scanf("%s", a);
    for(int i = 0; i < strlen(a); i++) {
        if(a[i] >= 'A' && a[i] < 'Z') {
            a[i] += 1;
        }else if(a[i] >= 'a' && a[i] < 'z') {
            a[i] += 1;
        }else if(a[i] == 'Z' || a[i] == 'z') {
            a[i] -= 25;
        }
    }
    printf("%s",a);
    return 0;
}
