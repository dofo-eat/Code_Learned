/*************************************************************************
	> File Name: 递归二分法.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年10月31日 星期四 17时43分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int dicho(int *arr, int left, int right,int find) {
    if(left <= right ) {
        int mid = (left + right) / 2;
        if(arr[mid] == find) {
            return mid;
        }
        else if(arr[mid] > find) {
            return dicho(arr, left, mid - 1,find);
        }
        else {
            return dicho(arr, mid + 1, right, find);
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d",&n);
    int find;
    scanf("%d", &find);
    int arr[10];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d",dicho(arr, 0, n - 1, find));
    return 0;
}
