/*************************************************************************
	> File Name: n阶数字三角形.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年10月27日 星期日 10时06分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n; 
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = n - i; j >= 1; j--){
            printf("%d",i);
            if(j != 0){
                printf(" ");
            }
        }
        printf("%d\n",i);
    }
    return 0;
}
