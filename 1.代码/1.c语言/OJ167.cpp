/*************************************************************************
	> File Name: OJ167.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月14日 星期四 19时00分26秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;
    int str1 = a.length();
    cout << str1 << endl;
    int sum = 0;
    for(int i = 0; i < str1; i++) {
        if(a[i] == 'a') {
            sum = i + 1;
            cout << sum << endl;
            break;
        }
    }
    a.insert(n - 1,b);
    cout << a << endl;
    return 0;
}
