/*************************************************************************
	> File Name: OJ168.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月14日 星期四 19时42分31秒
 ************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main () {
    int n;
    cin >> n;
    string a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        transform(a[i].begin(), a[i].end(), a[i].begin(),::tolower);
        a[i][0] -= 32;
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]){
                string temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
