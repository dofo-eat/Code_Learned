/*************************************************************************
	> File Name: 字符串操作.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月03日 星期三 20时32分09秒
 ************************************************************************/
 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;
    if (a.size() > 100) {
        cout << 100 << endl;
    } else {
        cout << a.size() << endl;
    }
    a = a.insert(n - 1, b);
    cout << a << endl;
    for (int i = a.size() - 1, j = 1; i >= 0; i--, j++) {
        if (a[i] == 'x') {
            cout << j << endl;
            break;
        }
    }
    return 0;
}
