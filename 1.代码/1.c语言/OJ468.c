/*************************************************************************
	> File Name: OJ468.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 19时37分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int gcd(int n, int m) {
    if (m <= n) {
	    if(m == 0) return n;
        else {
            return gcd(m,n % m);
        }
    } else {
        return gcd(m, n);
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int sum = gcd(n, m);
    printf("%d", sum);
    return 0;
}
