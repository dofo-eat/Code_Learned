/*************************************************************************
	> File Name: 2.scanf函数循环读入.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月01日 星期日 16时32分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    char str[100];
    int ret = 0;
    while ((ret = scanf("%[^\n]s", str)) != EOF) {
        getchar();
        printf("%s ret = %d\n", str, ret);
    }
    return 0;
}
