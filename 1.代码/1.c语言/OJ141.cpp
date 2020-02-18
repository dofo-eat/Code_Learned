/*************************************************************************
	> File Name: OJ141.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年01月09日 星期四 18时59分06秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    for(int i = 0; i <  n; i++) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        char x = 'A';
        x += i;
        for(int j = 0; j < n - i; j++) {
            cout << x;
            x++;
        }
        cout << x;
        for(int j = 0; j < n - i; j++) {
            x--;
            cout << x;
        }
        cout << endl;
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < n - i; j++) {
            cout << " ";
        }
        char x = 'A';
        x += n - i;
        for(int j = 0; j < i; j++) {
            cout << x;
            x++;
        }
        cout << x;
        for(int j = 0; j < i; j++) {
            x--;
            cout << x;
        }
        cout << endl;
    }
    return 0;
}
