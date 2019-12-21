/*************************************************************************
	> File Name: EP03.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 16时35分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 600851475143LL

int main() {
    long long int ans = 0, M = N;
    long long int i = 2;
    while(i * i <= M) {
        if(M % i == 0) ans = i;
        while(M % i == 0) M /= i;
        i += 1;
    }
    if(M > 1) ans = M;
    printf("%lld\n", ans);
    return 0;
}
