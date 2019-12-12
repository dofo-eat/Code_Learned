/*************************************************************************
	> File Name: OJ442.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月01日 星期日 20时50分54秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int step[30];
    int n, i;
    scanf("%d",&n);
    step[1] = 1;
    step[2] = 2;
    for(i = 3; i <= n; i++){
        step[i] =  step[i - 1] + step[i - 2];        
    }
    for(int i = 1; i <= n; i++){
        printf("%d",step[i]);
        i < n && printf(" ");
    }
    return 0;

}
