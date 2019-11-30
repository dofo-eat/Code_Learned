/*************************************************************************
	> File Name: OJ216.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月30日 星期六 14时57分09秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main () {
    int n;
    cin >> n;
    string a[101];
  //  char str[100];
    string str;
    for(int i = 0;i < n; i++) {
        cin >> str;
        a[i] = &str[3];
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                string temp = a[j];
                a[j] =  a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
