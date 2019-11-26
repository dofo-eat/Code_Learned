/*************************************************************************
	> File Name: OJ175.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月16日 星期六 17时30分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int a[31];
    scanf("%d", &n);
    int sum = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        if(a[i] >= 90 && a[i] <= 100) {
            sum++;
        }else if(a[i] >= 80 && a[i] <= 89) {
            sum1++;
        }else if(a[i] >= 60 && a[i] <= 79) {
            sum2++;
        }else{
            sum3++;
        }
    }
    printf("You %d\n",sum);
    printf("Liang %d\n", sum1);
    printf("Zhong %d\n", sum2);
    printf("Cha %d\n", sum3);
    return 0;
}
