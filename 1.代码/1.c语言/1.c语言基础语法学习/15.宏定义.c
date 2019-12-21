/*************************************************************************
	> File Name: 15.宏定义.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月12日 星期四 18时30分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX(a, b) ({\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    __a > __b ? __a : __b;\
})

#define P(func) {\
    printf("%s = %d\n", #func,func);\
}

int main() {
    int a = 7;
    printf("%d\n", MAX(2, 3));
    printf("%d\n", 5 + MAX(2, 3));
    printf("%d\n", MAX(2, MAX(3, 4)));
    printf("%d\n", MAX(2, 3 > 4 ? 3 : 4));
    printf("%d\n", MAX(a++, 6));
    printf("%d\n", a);
    return 0;
}
