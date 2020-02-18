/*************************************************************************
	> File Name: 括号匹配.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月07日 星期五 22时07分06秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main () {
    char str[50050];
    cin >> str;
    stack<char> sta;
    int flag = 0;
    int sum[50050][2], a = 0, b = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == '(') {
            sta.push(i + 1);
        } 
        if (str[i] == ')'){
            if(sta.empty()) {
                flag = 1;
                break;
            }
            sum[a][0] = sta.top();
            sum[a][1] = i + 1;
            a++;
            sta.pop();
        }
    }
    if(sta.empty() && !flag) {
        cout << "Yes" << endl; 
        for(int  i = 0; i < a; i++) {
            cout << sum[i][0] << " " << sum[i][1];
            i < a - 1 && cout << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
