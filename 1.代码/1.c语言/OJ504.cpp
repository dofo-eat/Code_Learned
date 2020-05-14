/*************************************************************************
	> File Name: OJ504.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月13日 星期三 18时41分44秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string str;
int n;

int main() {
    cin >> str >> n;
    for(int i = 0; i < n; i++) {
        int ind = str.size() - 1;
        for(int j = 0; j < str.size() - 1; j++) {
            if(str[j] > str[j + 1]) {
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }
    int flag = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] != '0') flag = 1;
        if(flag) cout << str[i];
    }
    cout << endl;
    return 0;
}
