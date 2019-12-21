/*************************************************************************
	> File Name: 15.LOG封装.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月12日 星期四 19时17分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define DEBUG
#ifdef DEBUG

#define log(frm, arg...) {\
    printf("[%s : %s : %d]", __FILE__, __func__, __LINE__ );\
    printf(frm, ##arg);\
    printf("\n");\
}
// 只有arg 的时候就会对他进行合法性判断 ， 所以不合法  一个#是会把ARG 变成一个字符串”“
#else
#define log(fre, arg...)
#endif//用来结束define DEBUG 和ifdef DEBUG
#define contact(a, b) a##b

//##代表连接 如果一个变量前面有他， 就停止展开

int main() {
    int a = 123;
    //A(B(a)); => B(a) + 3 => a * 2 + 3
    int abcdef = 15; 
    //printf("[%s : %s : %d] %d\n", __FILE__, __func__, __LINE__, a);
    contact(abc, def) = 23;
    log("%d", a);
    log("hello world");
    log("%d", abcdef);
    return 0;
}
