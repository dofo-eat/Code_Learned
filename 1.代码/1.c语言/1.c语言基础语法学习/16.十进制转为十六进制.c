/*************************************************************************
	> File Name: 16.十进制转为十六进制.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月12日 星期四 20时31分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<inttypes.h>
void test_sscanf() {
    char str1[] = "123 456 456 987";
    char str2[100];
    int a, b, c, d;
    sscanf(str1, "%d%[^$]s", &a, str1);
    sscanf(str1, "%d%[^$]s", &b, str1);
    sscanf(str1, "%d%[^$]s", &c, str1);
    sscanf(str1, "%d%[^$]s", &d, str1);
    int offset = 0;//定义一个偏移量
    offset += sprintf(str2 + offset, "a = %d", a);
    offset += sprintf(str2 + offset, "b = %d", b);
    offset += sprintf(str2 + offset, "c = %d", c);
    offset += sprintf(str2 + offset, "d = %d", d);
    printf("%s\n", str2);
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
}

uint64_t strlen1(const char *str) {//const 代表当前字符串可以访问 不可以更改
    uint64_t i = 0;
    while(str[i]) i++;
    return i;
}
int strcmp1(const char *str1, const char *str2) {
    uint64_t i = 0;
    for(; str1[i] && str2[i];) {
        if(str1[i] - str2[i]) return str1[i] - str2[i];
    }
    return str1[i] - str2[i];
}

int main() {
    int n;
    test_sscanf();
     char str[100];
    /*while(~scanf("%d", &n)) {
        printf("%x\n", n);
        sprintf(str, "%x", n);
        printf("%s has %d digit\n", str, strlen(str));
        
    }*/
    return 0;
}
