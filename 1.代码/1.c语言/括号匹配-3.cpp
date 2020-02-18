/*************************************************************************
	> File Name: 括号匹配-3.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月10日 星期一 19时50分37秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool ismatch(string str) {
    stack<char> sta;
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') {
            sta.push('(');
        } else if (str[i] == '[') {
            sta.push('[');
        } else if (str[i] == '{') {
            sta.push('{');                          
        } else if (str[i] == ')') {
            if(sta.empty()) {
                return 0;
            } else {
                char temp = sta.top();
                sta.pop();
                if(temp == '(') {
                    return 0;
                }
            }
        } else if(str[i] == ']') {
            if(sta.empty()) {
                return 0;
            } else {
                char temp = sta.top();
                sta.pop();
                if(temp == '[') {
                    return 0;
                }
            }
        } else if(str[i] == '}') {
            if(sta.empty()) {
                return 0;
            } else {
                char temp = sta.top();
                sta.pop();
                if(temp == '{') {
                    return 0;
                }
            }
        } else {
            continue;
        }
    }
    if(sta.size() != 0) {                    
        return 0;
    }
    return 1;
}       

int main () {
    string str;
    cin >> str;
    if(ismatch(str)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
