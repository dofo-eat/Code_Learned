/*************************************************************************
	> File Name: 1.sprintf函数.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月01日 星期日 16时56分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    char str[100];
    int ret;
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sprintf(str, "%d.%d.%d.%d",a, b, c, d);
    FILE * fd = fopen("out", "wb");// 文件指针FILE wb以二进制写
    fprintf(fd, "%s", str);//stdin stdout stderr  标准环境输入输出和错误输出
    printf("str = %s\n", str);
    return 0;
}
