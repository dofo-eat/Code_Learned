/*************************************************************************
	> File Name: 计算集和的并.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月05日 星期三 16时19分41秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<string>
using namespace std;

int main () {
    int n, m;
    int a, b;
    set<int> num;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a;
        num.insert(a);
    }
    for(int j = 0; j < m; j++) {
        cin >> b;
        num.insert(b);
    }
    set<int>::iterator it = num.begin();
    cout << (*it);
    it++;
    for(; it != num.end(); it++) {
        cout << " "<< (*it);
    }
    num.clear();
    return 0;
}
