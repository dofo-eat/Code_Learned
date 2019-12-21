/*************************************************************************
	> File Name: OJ211.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月13日 星期五 16时05分46秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main () {
    int n;
    cin >> n;
    string a[30];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
