/*************************************************************************
	> File Name: OJ170.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月15日 星期五 20时09分32秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a[1000];
    string c = "No_smoking";
    string d = "Ban_smoking";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int change;
    for(int i = 0; i < n; i++) {
        change = a[i].find(d);
        for(int j = 0; j < a[i].length(); j++) {
            if(change != -1) {
                a[i].replace(change, c.length() + 1, c);
                change = a[i].find(d);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
