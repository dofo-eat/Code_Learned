/*************************************************************************
	> File Name: OJ165.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月13日 星期三 20时42分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    long long int c;
    long long int sum = 0;
    long long int a;
    scanf("%lld", &c);
    for(long long int i = 1; i < c; i++) {
        a = sqrt(c * c - i * i);
        if(a * a + i * i == c * c){
            sum++;
        } 
    }
    printf("%lld", sum / 2);
    return 0;
}
