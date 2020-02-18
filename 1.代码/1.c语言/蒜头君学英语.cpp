/*************************************************************************
	> File Name: 蒜头君学英语.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月06日 星期四 18时32分41秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<string>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a;
    string b;
    set<string> str;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        for(int i = 0; i < b.length(); i++) {
            if(b[i] >=  'a' && b[i] <= 'z') {
                b[i] -= 32;
            }
        }
        if(a == 0) str.insert(b);
        if(a == 1){
            if(str.count(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
