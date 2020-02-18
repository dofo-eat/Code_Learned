/*************************************************************************
	> File Name: OJ151.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月12日 星期二 20时39分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main () {
    char L1, L2, R1, R2;
    scanf("%c %c %c %c", &L1, &R1, &L2, &R2);
    if((L1 == 'O' && L2 == 'Y') || (L1 == 'Y' && L2 == 'H') || (L1 == 'H'  && L2 == 'O')) {
        if((L1 == 'O' && R2 == 'Y') || (L1 == 'Y' && R2 == 'H') || (L1 == 'H'  && R2 == 'O') || (L1 == R2)){
            printf("MING");
        }
        else {
            if((R1 == 'O' && R2 == 'Y') || (R1 == 'Y' && R2 == 'H') || (R1 == 'H'  && R2 == 'O')) {
                printf("MING");
            }
            else {
                printf("LIHUA");
            }
        }
    } else if(L1 == L2) {
        if((R1 == 'O' && R2 == 'Y') || (R1 == 'Y' && R2 == 'H') || (R1 == 'H'  && R2 == 'O')) {
            printf("MING");
        }
        else {
            if(R1 == R2){
                printf("TIE");
            } else{
                printf("LIHUA");
            }
        }
    } else {   
        if((R1 == 'O' && L2 == 'Y') || (R1 == 'Y' && L2 == 'H') || (R1 == 'H' && L2 == 'O')) {
            if((R1 == 'O' && R2 == 'Y') || (R1 == 'Y' && R2 == 'H') || (R1 == 'H'  && R2 == 'O') || (R1 == R2)) {
                printf("MING");
            } else {
                printf("LIHUA");
            }
        }else {
            printf("LIHUA");
        }
    }
    return 0;
}

