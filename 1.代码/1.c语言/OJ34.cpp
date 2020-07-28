/*************************************************************************
	> File Name: OJ34.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月27日 星期一 17时31分30秒
 ************************************************************************/
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
        cout << "L" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}

