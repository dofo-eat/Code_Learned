/*************************************************************************
	> File Name: OJ218.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月30日 星期六 19时39分47秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[1000002], b[1000002];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i] == b[j]) {
                b[j] = -1;
                cout << j + 1;
                break;
            }
        }
        i < n - 1 && cout << " ";
    }
    return 0;
}
