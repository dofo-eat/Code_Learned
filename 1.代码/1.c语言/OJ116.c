/*************************************************************************
	> File Name: OJ116.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月05日 星期二 23时02分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define swap(a, b) {\
    __typeof(a)__temp = a;\
    a = b; b = __temp;\
}

void bubble_sort(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(arr[j] >= arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    int n = 3;
    int arr[3];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr,n);
    int a = arr[0], b = arr[1], c = arr[2];
    if((a + b) > c ) {
        if((a * a + b * b) > (c * c)) {
            printf("acute triangle");
        }else if((a * a + b * b) == (c * c)) {
            printf("right triangle");
        }else{
            printf("obtuse triangle");
        }
    }else{
        printf("illegal triangle");
    }
    return 0;
}
