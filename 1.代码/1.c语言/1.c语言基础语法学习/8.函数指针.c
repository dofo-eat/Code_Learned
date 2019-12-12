/*************************************************************************
	> File Name: 8.函数指针.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月07日 星期六 15时18分31秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

typedef int64_t int1;
int1 Triangle(int1 n) {
    return n * (n + 1) / 2;
}

int1 Pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 Hexagonal(int1 n) {
    return n * (2 * n - 1);
}

int1 binary_search(int1 (*func)(int1), int1 x) {
    int head = 1, tail = x, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(Pentagonal(mid) == x) return mid;
        if(Pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
} 
int main () {
    int n = 144;
    for(;;n++) {
        if(binary_search(Pentagonal, Hexagonal(n)) == -1) continue;
        printf("%"PRId64"\n",Hexagonal(n));break;
    }
    return 0;
}
