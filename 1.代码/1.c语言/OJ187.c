/*************************************************************************
	> File Name: OJ187.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月19日 星期二 19时08分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long int hanio(long long int n) {
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 3;
    }else if(n == 3) {
        return 7;
    }
    return 2 * hanio(n - 1) + 1;
}
long long int ci(long long int n) {
    if(n == 1) {
        return 1;
    }else if(n == 2) {
        return 4;
    }else if(n == 3) {
        return 11;
    }
    return 2 * ci(n - 1) + n;
}
int main() {
    long long int n;
    scanf("%lld", &n);
    printf("%lld %lld",hanio(n), ci(n));
    return 0;
}
