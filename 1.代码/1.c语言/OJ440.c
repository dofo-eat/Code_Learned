/*************************************************************************
	> File Name: OJ440.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月30日 星期六 20时45分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cy(int i,int x) {
    int sum = 0;
    while(i){
        int n = i % 10;
        if(x == n) sum++;
        i /= 10;
    }
    return sum;
}

int main() {
    int n, x, ans = 0;
    scanf("%d %d", &n, &x);
    for(int i = 1; i <= n; i++){
        ans += cy(i, x);
    }

    printf("%d", ans);
    return 0;
}
