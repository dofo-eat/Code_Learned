/*************************************************************************
	> File Name: OJ209.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月13日 星期五 15时14分48秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[105];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    } 
    return 0;
}
