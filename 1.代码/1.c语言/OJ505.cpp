/*************************************************************************
	> File Name: OJ505.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月13日 星期三 18时52分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
string str[100005];

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for(int i = 0; i < n; i++) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}
