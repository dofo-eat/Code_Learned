/*************************************************************************
	> File Name: OJ173.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月16日 星期六 14时25分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char a[1001];
    int sum = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    scanf("%[^\n]s", a);    
    for(int i = 0; i < strlen(a); i++) {
        if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) {
            sum++;
        }else if(a[i] >= '0' && a[i] <= '9') {
            sum1++;
        }else if(a[i] == ' ') {
            sum2++;
        }else {
            sum3++;
        }
    }
    printf("%d %d %d %d",sum, sum1,sum2,sum3);  
    return 0;
}
