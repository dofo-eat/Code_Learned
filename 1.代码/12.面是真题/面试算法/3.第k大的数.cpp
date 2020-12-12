/*************************************************************************
	> File Name: 3.第k大的数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年09月02日 星期三 08时31分20秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int find_kth_number(int *num1, int *num2, int n, int k) {
    int ind1[2], ind2[2];
    ind1[0] = 0;
    ind2[0] = 0;
    while (k > 1) {
        if (ind1[0] == n || ind2[0] == n) break;
        ind1[1] = ind1[0] + k / 2;
        if (ind1[1] > n) ind1[1] = n;
        ind2[1] = ind2[0] + (k - (ind1[1] - ind1[0]));
        if (num1[ind1[1] - 1] < num2[ind2[1] - 1]) {
            k -= (ind1[1] - ind1[0]);
            ind1[0] = ind1[1];
        } else {
            k -= (ind2[1] - ind2[0]);
            ind2[0] = ind2[1];
        }
    }
    if (ind1[0] == n) {
        return num2[ind2[0] + k - 1];
    } else if (ind2[0] == n) {
        return num1[ind1[0] + k - 1];
    }
    return num1[ind1[0]] < num2[ind2[0]] ? num1[ind1[0]] : num2[ind2[0]];
}

int main() {
    int n;
    scanf("%d", &n);
    int *num1 = malloc(n * sizeof(int));
    int *num2 = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d ", &num1[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d ", &num2[i]);
    }
    int m, tp;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &tp);
        printf("%d\n", find_kth_number(num1, num2, n, tp));
    }
    return 0;
}
