/*************************************************************************
	> File Name: 2.scanf函数输入字符.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月01日 星期日 16时06分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    printf("  %d\n", printf("%s", str));
    return 0;
}
