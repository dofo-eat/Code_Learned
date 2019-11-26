/*************************************************************************
	> File Name: OJ166.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月14日 星期四 16时26分57秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;
    int str1 = a.length();
    if(str1 > 100) {
        cout << 100 << endl;
    }else{
        cout << str1 << endl;
    }
    a.insert(n - 1, b);
    cout << a << endl;
    int str2 = a.length();
    int sum = 0;
    for(int i = str2 - 1; i >= 0; i--) {
        sum++;
        if(a[i] == 'x') {
            break;
        }
    }
    cout << sum << endl;
    return 0;
}
