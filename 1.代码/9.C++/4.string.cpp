/*************************************************************************
	> File Name: 4.string.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月21日 星期二 20时07分33秒
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "hello", s2 = "world";
    s1 += "";
    s1 += s2;
    cout << s1 << endl;
    for(int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }
    return 0;
}
