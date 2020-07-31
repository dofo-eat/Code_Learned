/*************************************************************************
	> File Name: 19.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月31日 星期五 11时58分06秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j]) {
                cout << a[i];
                break;
            }
        }
    }
    return 0;
}
