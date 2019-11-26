/*************************************************************************
	> File Name: OJ104.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月04日 星期一 22时59分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n % 10 == 9) {
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
