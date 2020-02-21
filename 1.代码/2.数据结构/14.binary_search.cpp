/*************************************************************************
	> File Name: 14.binary_search.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月20日 星期四 20时34分27秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define p(func, args...) {\
    printf("%s = %d\n", #func, func(args));\
}
//args...是变参
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(num[mid] == x) return mid;
        if(num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;//没找到
}

//1111111100000000最后一个1
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;//head 虚拟头
    while(head < tail) {
        //二分的区间, 返回的是head的指向
        mid = (head + tail + 1) >> 1;//为了避免死循环的条件这里要加1, 根据题目加减数据不一定
        if(num[mid] == 1) head = mid;
        else tail = mid - 1;
    } 
    return head;
}

//0000000011111111第一个1
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;//虚拟尾指针
    while(head < tail) {
        mid = (head + tail) >> 1;//不会陷入死循环
        if(num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1: head;//是否找到
}

int main () {
    int arr1[10]= {1,3,5,7,9,11,13,17,19,21};
    int arr2[10]= {1,1,1,1,0,0,0,0,0,0,};
    int arr3[10]= {0,0,0,0,0,0,1,1,1,1};
    p(binary_search1, arr1, 10, 7);
    p(binary_search2, arr2, 10);
    p(binary_search3, arr3, 10);
    return 0;
}
