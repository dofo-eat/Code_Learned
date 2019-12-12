/*************************************************************************
	> File Name: funcA.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月08日 星期日 18时13分39秒
 ************************************************************************/

#include<stdio.h>
#include"2.funcB.h"
int funcA(int n) {
    printf("funcA : %d\n", n);
    if(n == 0) return 1;
    funcB(n - 1);
    return n;
}
