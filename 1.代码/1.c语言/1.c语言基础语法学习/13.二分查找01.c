/*************************************************************************
	> File Name: 13.二分查找01.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月10日 星期二 19时43分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//查找最后一个1
int binary_search(int *arr, int n) {
    int l = -1, r = n - 1, mid;
    while(l < r) {
        mid = (l + r + 1) / 2;
        if(arr[mid] == 1) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int arr[100];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("%d", binary_search(arr, n));
    return 0;
}
