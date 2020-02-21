/*************************************************************************
	> File Name: 13.unstable_sort.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月20日 星期四 18时32分12秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int ) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

void select_sort(int *num, int n) {
    for(int i = 0; i < n - 1; i++) {
        int ind = i;
        for(int j = i + 1; j < n; j++) {
            if(num[ind] > num[j]) ind = j;
        }
        swap(num[i], num[ind]);
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if(r < l) return ;
    int x = l, y = r, z = num[l];
    while(x < y) {
        while(x < y && num[y] >= z) y--;
        if(x < y) num[x] = num[y];
        while(x < y && num[x] <= z) x++;
        if(x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

void randint(int *arr, int n) {
    while(n--) arr[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("\n");
    return ;
}

int main () {
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    randint(arr, max_op);
    TEST(arr, max_op, select_sort, num, max_op);
    TEST(arr, max_op, select_sort, num, max_op);
    return 0;
}
