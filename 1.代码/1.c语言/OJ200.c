/*************************************************************************
	> File Name: OJ200.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月23日 星期六 11时43分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int sl(int n) {
    
}
int main() {
    int n;
    double ans = 0;
    scanf("%d", &n);
    int a = 3, b = 4.0;
    while(n--) {
        b = a + b;
        a = b - a;
        ans += a * 1.0 / b;

    }
    printf("%d/%d\n",a, b);
    printf("%.2f", ans);
    return 0;
}
