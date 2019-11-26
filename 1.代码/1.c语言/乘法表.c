/*************************************************************************
	> File Name: 乘法表.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年10月27日 星期日 12时45分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            printf("%d * %d = %d ",i,j,i*j);
        }
        printf("\n");
    }
    return 0;
}
