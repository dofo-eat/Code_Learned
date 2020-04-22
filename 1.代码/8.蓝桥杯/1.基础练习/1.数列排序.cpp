/*************************************************************************
	> File Name: 1.数列排序.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月22日 星期三 14时06分21秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,  a + n);
    for(int i = 0; i < n; i++) {
        cout << a[i];
        i < n - 1 && cout << " "; 
    }
    return 0;
}
