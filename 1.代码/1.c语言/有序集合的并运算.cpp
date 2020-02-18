/*************************************************************************
	> File Name: 有序集合的并运算.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月14日 星期五 21时20分22秒
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
        cout << num.size() << endl;
    for(set<int>::iterator it = num.begin(); it != num.end(); it++) {
                cout << (*it) <<  " ";    
            
    }
        num.clear();
        return 0;

}

