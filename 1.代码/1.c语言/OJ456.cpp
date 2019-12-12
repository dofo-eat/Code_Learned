/*************************************************************************
	> File Name: OJ456.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月07日 星期六 14时08分18秒
 ************************************************************************/
#include<iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[400000] = {0};
    int b[400000] = {0};
    int temp = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;    
    }
    for(int i = 0; i < n; i++) {
        if(b[a[i]] % 2 != 0) {
            cout << a[i];
            break;        
        }   
    }
    return 0;
}
