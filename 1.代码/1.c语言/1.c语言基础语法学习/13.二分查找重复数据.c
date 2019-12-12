/*************************************************************************
	> File Name: 13.二分查找重复数据.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月10日 星期二 19时21分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int binary_search(int *arr, int n, int x){
    int l = 0, r = n, mid;
    while(l < r) { //不可以是l <= r
        mid = (l + r) / 2;
        if(arr[mid] > x) r = mid;
        else l = mid + 1;
    }
    return l == n ? -1 : l;
}

int main() {
    int arr[100];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    scanf("%d", &x);
    printf("%d", binary_search(arr, n, x));
    return 0;
}
