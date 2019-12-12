/*************************************************************************
	> File Name: OJ208.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月11日 星期三 20时59分10秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

bool cmp (int a, int b) {
    return a > b;
}

int main () {
    int n, m;
    cin >> n;
    int a[105];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++) {
        if(a[i] < a[m - 1]){
            cout << i;
            break;
        }
    }
    return 0;
}
