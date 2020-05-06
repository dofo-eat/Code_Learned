/*************************************************************************
	> File Name: 7.特殊的数字.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 11时12分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    for(int i = 100; i < 1000; i++) {
        int a = i /100;
        int b = i / 10 % 10;
        int c = i % 10 % 10;
        if(i == a * a * a + b * b * b + c * c * c) {
            cout << i << endl;
        }
    }
    return 0;
}
