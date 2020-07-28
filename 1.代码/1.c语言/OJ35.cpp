/*************************************************************************
	> File Name: OJ35.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月27日 星期一 17时42分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a >= 0 && a < b){
        for(int i = a; i <= b; i++) {
            cout << i << endl;
        }
        
    }else if(a < 0 && b > 0){
        for(int i = 0; i <= b; i++) {
            cout << i << endl;
        }
    } 
    else {
        cout << "ERROR" << endl;
    }
    return 0;
}
