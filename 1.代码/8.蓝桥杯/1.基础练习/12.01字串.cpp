/*************************************************************************
	> File Name: 12.01字串.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月08日 星期五 11时33分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i < 32; i++) {
        cout << i % 32 / 16 << i % 16 / 8 << i % 8 / 4 << i % 4 / 2 << i % 2 << endl;
    }
    return 0;
}
