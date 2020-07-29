/*************************************************************************
	> File Name: OJ66.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月29日 星期三 12时32分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
int check[MAX_N + 5];

int func(int n) {
    int sum = 0;
    while(n != 1) {
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        sum++;
    }
    return sum;
}
int main() {
    int a[MAX_N + 5];
    for(int i = 2; i < 1000000; i++) {
        a[i] = func(i);
    }
    int max = 1, t = 0;
    for(int i = 2; i < 1000000; i++) {
        if(max < a[i]) {
            t = i;
        }
    }
    cout << t << endl;
    return 0;
}
