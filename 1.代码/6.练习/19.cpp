/*************************************************************************
	> File Name: 19.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月28日 星期二 15时04分50秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int n;
    while(cin >> n) {
        auto iter = find(v.begin(), v.end(), n);
        if(iter == v.end()) {
            v.push_back(n);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for(auto iter = v.begin(); iter != v.end(); iter++ ) {
        cout << *iter << endl;
    }
    return 0;
}
