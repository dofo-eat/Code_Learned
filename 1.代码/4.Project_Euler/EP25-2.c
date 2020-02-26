/*************************************************************************
	> File Name: EP25-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 14时18分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int f[3][1005];

int main() {
    int n = 2;
    f[1][0] = 1;
    f[1][1] = 1;
    f[2][0] = 1;
    f[2][1] = 1;
    while(f[n % 3][0] < 1000) {//判断当前位数是否小于1000
        n += 1;
        int *a = f[n % 3], *b = f[(n - 1) % 3], *c = f[(n - 2) % 3];
        for(int i = 1; i <= b[0]; i++) {
            a[i] = b[i] + c[i];
        }
        a[0] = b[0];
        for(int i = 1; i <= a[0]; i++) {
            if(a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (a[0] == i);
        }
    }
    printf("%d\n", n);
    return 0;
}
