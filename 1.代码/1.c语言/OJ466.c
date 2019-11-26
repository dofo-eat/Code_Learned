/*************************************************************************
	> File Name: OJ466.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 20时02分20秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
int pc(int n) {
    int sum = 0;
    int c = 0, temp = n;
    while(n) {
        c = c * 10 + n % 10;
        n /= 10;
    }
    return temp == c;
    
}
int main() {
    int n,sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) { 
        if(pc(i)) {
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
}
