/*************************************************************************
	> File Name: 6.回文数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月23日 星期四 17时44分33秒
 ************************************************************************/
#include<stdio.h>

int pc(int n) {
    int c = 0, temp = n;
    while(n) {
        c = c * 10 + n % 10;
        n /= 10;
    }
    return temp == c;
}

int main() {
    int c = 0;
    for(int i = 0; i < 10000; i++) { 
        if(pc(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
