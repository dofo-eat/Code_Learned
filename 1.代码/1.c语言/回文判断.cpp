/*************************************************************************
	> File Name: 回文判断.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月17日 星期一 14时49分34秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>

bool is(char *a) {
    int len = strlen(a) - 1;
    for(int i = 0; i < len/2; i++) {
        if(a[i] != a[len -1 - i]) return false;
        return true;
    }
}

int main () {
    char a[105];
    gets(a); 
    if(!is(a)) puts("false\n");
    puts("true\n");
    return 0;
}
