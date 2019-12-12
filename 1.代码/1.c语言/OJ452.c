/*************************************************************************
	> File Name: OJ452.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月06日 星期五 18时41分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define swap(a, b) {\
__typeof(a) __temp = a;\
a = b; b = __temp;\
}

int bubble(int *a, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                sum++;
            }
        }
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[10001] = {0};
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d",bubble (a, n));
    return 0;
}
