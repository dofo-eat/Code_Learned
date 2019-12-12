/*************************************************************************
	> File Name: 13.二分查找2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月10日 星期二 18时42分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// 0 1 2 3 4 5 6 7 8 9
// 0 1 4 9 16 25 36 49 64 81

int f(int x) {
    return x * x;
}
int binary_search(int (*arr)(int), int y){
    int l = 0, r = y, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(arr(mid) == y) return mid;
        if(arr(mid) < y) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        while (n--) {
            int x;
            scanf("%d", &x);
            printf("x = %d\n", binary_search(f, x));
        }
    }
    return 0;
}
