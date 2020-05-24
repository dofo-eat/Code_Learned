/*************************************************************************
	> File Name: 第一个合理的位置.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月23日 星期六 17时51分18秒
 ************************************************************************/
#include <stdio.h>
int find_first_location(int *num, int len, int target) {
    int l = 0, r= len -1, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(num[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main() {
    int num[100000];
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int value;
        scanf("%d", &value);
        printf("%d\n", find_first_location(num, n, value));
    }
    return 0;
}
