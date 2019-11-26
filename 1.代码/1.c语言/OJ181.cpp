/*************************************************************************
	> File Name: OJ181.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月16日 星期六 20时33分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
    string a;
    cin >> a;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] >= 'a' && a[i] <= 'z') {
            a[i] -= 32;
        }else if(a[i] >= 'A' && a[i] <= 'Z') {
            a[i] += 32;
        }
    }
    cout << a << endl;
    return 0;
}
