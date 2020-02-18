/*************************************************************************
	> File Name: 水果店.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月07日 星期五 12时49分43秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int main () {
    int n, num = 0;
    cin >> n;
    string str1, str2;
    map <string, map<string, int> > a;
    for(int i = 0; i < n; i++) {
        cin >> str1 >> str2 >> num;
        a[str2][str1] += num;
    }
    for(map<string, map<string, int> >::iterator it = a. begin(); it != a.end(); it++) {
        cout << it->first<< endl;
        for(map<string, int>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++) {
            cout << "   |----" << it1->first << "(" << it1->second << ")" << endl;
        }
    }
    return 0;
}
