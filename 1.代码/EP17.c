/*************************************************************************
	> File Name: EP17.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月21日 星期六 15时12分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int get_letters(int n) {
    static int arr1[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    static int arr2[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
    if(n < 20) {
        return arr1[n];
    } else if(n < 100) {
        return arr2[n / 10] + arr1[n % 10];
    } else if(n < 1000) {
        if(n % 100 == 0) {
            return arr1[n / 100] + 7;
        }
        return arr1[n / 100] + 10 + get_letters(n % 100);
    }
    else {
        return 11;
    }
}

int main() {
    int sum = 0;
    for(int i = 1; i <= 1000; i++) {
        sum += get_letters(i);
    }    
    printf("%d\n", sum);
    return 0;
}
