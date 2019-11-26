/*************************************************************************
	> File Name: OJ117.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月06日 星期三 18时45分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int a;
    int flag = 0;
    scanf("%d", &a);
    int arr[10] = {0};
    while(a) {
       arr[++arr[0]] = a % 10;
        a /= 10;
    }
    for(int i = 1; i <= arr[0] && !flag; i++) {
            if(arr[i] != arr[arr[0] - i + 1]) {
                printf("NO\n");
                flag = 1;
            }
    }
    !flag && printf("YES\n");
    return 0;
}
