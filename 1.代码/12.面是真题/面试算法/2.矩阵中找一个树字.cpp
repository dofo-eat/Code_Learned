/*************************************************************************
	> File Name: 2.矩阵中找一个树字.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年09月02日 星期三 08时13分04秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int find_target(int ** matrix, int n, int m, int target) {
    if(target > matrix[n - 1][m - 1]) return 0;
    int l = 0 , r = n - 1, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(matrix[mid][m - 1] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int i = l;
    l = 0, r = m - 1;
    while(l <= r) {
        mid = (l + r) / 2;
        if(matrix[i][mid] == target) return 1;
        if(matrix[i][mid] < target) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    return 0;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int ** v;
    v = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        v[i] = (int*)malloc(m * sizeof(int));
    }
    int tp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){
            scanf("%d", &v[i][j]);
        }
    }
    int tot;
    scanf("%d", &tot);
    for (int i = 0; i < tot; ++i) {
        scanf("%d", &tp);
        if (find_target(v, n, m, tp)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
