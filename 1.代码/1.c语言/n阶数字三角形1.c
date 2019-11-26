/*************************************************************************
	> File Name: n阶数字三角形1.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年10月27日 星期日 11时03分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for (int j = n - i; j >= 1; j--) {
            printf("%d", j);
            if (j > 1) {
                printf(" ");
            }
        }
        printf("\n");
    }   
    return 0;
}
