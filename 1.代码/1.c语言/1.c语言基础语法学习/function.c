/*************************************************************************
	> File Name: function.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月08日 星期日 16时28分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int funcA(int);//函数的声明

int funcB(int n) {
    printf(":funcB: %d\n", n);
    if(n == 0) return 0;
    funcA(n - 1);
    return n;
}

int funcA(int n) {
    printf("funcA:%d\n", n);
    if(n == 0) return 0;
    funcB(n - 1);
    return n;
}
int main() { 
    funcA(6);
    funcB(6);
    return 0;
}
