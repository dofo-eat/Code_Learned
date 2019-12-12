/*************************************************************************
	> File Name: OJ203.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月07日 星期六 20时50分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int m,n;
    cin >> m >> n;
    int heig = 0;
    int a[11], b[11];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j][i] > heig){
                heig = a[j][i];
            }
            cout << heig << endl;
        } 
    }
}
