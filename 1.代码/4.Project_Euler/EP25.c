/*************************************************************************
	> File Name: EP25.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 14时12分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int f[3];

int main() {
    int n = 2;
    f[1] = 1;
    f[2] = 1;
    while(floor(log10(f[n % 3])) + 1 < 3) {
        n += 1;
        f[n % 3] = f[(n - 1) % 3] + f[(n - 2) % 3];
        printf("%d\n", f[n % 3]);
    }
    return 0;
}
