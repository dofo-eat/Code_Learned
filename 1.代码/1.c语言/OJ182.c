/*************************************************************************
	> File Name: OJ182.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 14时08分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
void  bubble_sort(int *numbers, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(numbers[j] >= numbers[j + 1]) continue;
            swap(numbers[j], numbers[j + 1]);
        }
    }
    return ;
}
int main() {
    int n;
    int a[1000000];
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    bubble_sort(a, n);
    printf("%d",a[0]);
    return 0;
}
