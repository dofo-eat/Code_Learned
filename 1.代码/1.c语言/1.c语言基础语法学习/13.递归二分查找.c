/*************************************************************************
	> File Name: 13.递归二分查找.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月10日 星期二 18时57分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int binary_search(int *arr, int l, int r, int x) {
    if(l > r) return -1;
    int mid = (l + r) / 2;
    if(arr[mid] == x) return mid;
    else if(arr[mid] < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(arr, l, r, x);
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
    printf("%d\n", binary_search(arr, 0, n - 1, x));
    return 0;
}
