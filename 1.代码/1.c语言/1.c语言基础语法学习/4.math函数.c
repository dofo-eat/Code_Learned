/*************************************************************************
	> File Name: 4.math函数.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月01日 星期日 20时05分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<inttypes.h>
int main() {
    int8_t a = 12;
    int b = 22;
    //int16_t;
    //int32_t;
    printf("a = %lu, b = %lu\n",sizeof(a), sizeof(b));//lu 长的无符号整形
    printf("%d\n",b);
    printf("%"PRId8"\n", a);
   // printf("%s\n", PRId8);//PRId是一个宏定义的字符串格式占位符
    printf("%d\n", INT8_MIN);
    printf("%d\n", INT8_MAX);
    printf("%d\n", INT16_MIN);
    printf("%d\n", INT16_MAX);
    return 0;
}
