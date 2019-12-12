/*************************************************************************
	> File Name: 13.二分查找.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月10日 星期二 18时19分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int binary_search(int *arr, int n, int x) {
    int l = 0, r = n - 1, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    scanf("%d", &x);
    printf("%d\n",binary_search(arr, n, x));
    return 0;
}
