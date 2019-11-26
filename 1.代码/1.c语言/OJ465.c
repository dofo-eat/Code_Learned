/*************************************************************************
	> File Name: OJ465.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 20时38分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find(int n, int k){
    k--;
    if(k == 0)
    return n % 10;
    else
    return find(n / 10, k);
}
int main() {
    int n, k;
    scanf("%d %d",&n, &k);
    printf("%d",find(n, k));
    return 0;
}

