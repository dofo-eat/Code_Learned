#include<stdio.h>
#include<stdlib.h>
#define swap(a, b) {\
    __typeof(a)__temp = a;\
    a = b; b = __temp;\
}
void bubble_sort(int *a, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(a[j] >= a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main () {
    int n, i;
    scanf("%d", &n);
    int a[1000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    printf("%d", (a[n - 1]- a[0]));
    return 0;
}
