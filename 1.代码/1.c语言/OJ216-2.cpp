/*************************************************************************
	> File Name: 0.test.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月23日 星期四 18时27分39秒
 ************************************************************************/

#include<iostream>
#include <set>
using namespace std;

typedef pair<string, int> PSI;

int main() {
    set<PSI> s;
    string name;
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name;
        name = name.substr(name.find(".") + 1, name.size());
        s.insert(PSI(name, i));
    }
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        cout << iter->first << endl;
    }
    return 0;
}
