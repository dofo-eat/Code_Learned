/*************************************************************************
	> File Name: EP09.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月25日 星期三 17时50分32秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    long long a, b, c;
    for(int i = 1; i <= 400; i++) {
        for(int j = i + 1; j <= 400; j++) {
            c = 1000 - i - j;
            if(i * i + j * j == c * c) {
                cout << i <<endl;
                cout << j << endl;
                cout << i * j * c << endl;
                break;
            }
        }
    }
    return 0;
}
