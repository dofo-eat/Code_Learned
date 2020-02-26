/*************************************************************************
	> File Name: 2.找出三位数字组成的最大回文数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月23日 星期一 00时11分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

int is_pali(int n) {
    int m = n, a = 0;
    while(m) {
        a = a * 10 + m % 10;
        m /= 10;
    }
    if(a == n) return 1;
    return 0;
}

int main () {
    int sum = 1;
    int max = 0;
    for(int i = 100; i < 1000; i++) {
        for(int j = 100; j < 1000; j++) {
            sum = i * j;
            if(is_pali(sum) && sum > max) max = sum; 
        }
    }
    cout << max << endl;
    return 0;
}
