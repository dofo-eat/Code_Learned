/*************************************************************************
	> File Name: OJ151.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月12日 星期二 20时39分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int cmp(char a, char b) {
    if(a == b) {
        return TIE;
    }
}

int main () {
    char a, b;
    scanf("%s %s", &a, &b);
    if(a == 'O' && b == 'O') {
        printf("TIE");
    }else if(a == 'O' && b == 'Y') {
        printf("MING");
    }else if(a == 'O' && b == 'H') {
        printf("LI");
    }else if(a == 'Y' && b == 'O') {
        printf("LI");
    }else if(a == 'Y' && b == 'Y') {
        printf("TIE");
    }else if(a == 'Y' && b == 'H') {
        printf("MING");
    }else if(a == 'H' && b == 'O') {
        printf("MING");
    }else if(a == 'H' && b == 'Y') {
        printf("LI");
    }else {
        printf("TIE");
    }
    return 0;
}

