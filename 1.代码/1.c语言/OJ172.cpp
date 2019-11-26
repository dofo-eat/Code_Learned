/*************************************************************************
	> File Name: OJ172.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月15日 星期五 21时04分51秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string a[10];
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 10 - 1; i++) {
        for(int j = 0; j < 9 - i; j++) {
            if(a[j] > a[j + 1]) {
                string temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
