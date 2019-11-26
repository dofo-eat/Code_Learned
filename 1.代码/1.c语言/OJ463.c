/*************************************************************************
	> File Name: OJ463.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月19日 星期二 17时26分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int l, r, u, d;
    int l1, r1, u1, d1;
    int sum = 0;
    scanf("%d %d %d %d", &l, &r, &u, &d);
    scanf("%d %d %d %d", &l1, &r1, &u1, &d1);
    if(l > r1 || l1 > r || u > d1 || u1 > d) {
        printf("0");
    }
    else{
       printf("%d",((r < r1 ? r : r1) - (l > l1 ? l : l1)) * ((d < d1 ? d : d1) - (u > u1 ? u : u1)));
    }
    return 0;
}
