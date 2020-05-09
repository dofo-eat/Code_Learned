/*************************************************************************
	> File Name: 13.阶乘计算.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月08日 星期五 20时11分47秒
 ************************************************************************/

#include<iostream>
using namespace std;

int a[10005];

int main() {
    int n;
    cin >> n;
    a[0] = 1;
    int sum, c = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 10000; j++) {
            sum = a[j] * i + c;
            a[j] = sum % 10;
            c = sum / 10;
        }
    }
    for(int i = 10000; i>= 0;i--) {
        if(a[i] != 0) {
            for(int j = i; j >= 0; j--) {
                cout << a[j];
            }
            break;
        }
    }
    return 0;
}
