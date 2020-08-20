/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 18时17分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define COLOR(str, code) "\033[" #code "m" str "\033[0m"

//#define YELLOW(str) "\033[33m" str "\033[0m"
//#define RED(str) "\033[31m" str "\033[0m"
//#define BLUE(str) "\033[34m" str "\033[0m"
//#define GREEN(str) "\033[32m" str "\033[0m"

#define RED(str) COLOR(str, 31)
#define GREEN(str) COLOR(str, 32)
#define YELLOW(str) COLOR(str, 33)
#define BLUE(str) COLOR(str, 34)


int main() {
    printf(YELLOW("hello world\n"));
    printf("hello haizei\n");
    return 0;
}



/*
#define ABS(x) _Generic((x), int : abs, double : fabs)(x)


int main() {
    int a = -123;
    double b = -12.3;
    printf("%d\n", ABS(a));
    printf("%lf\n", ABS(b));

    return 0;
}*/
