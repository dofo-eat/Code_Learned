/*************************************************************************
	> File Name: OJ378.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月07日 星期五 14时13分16秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

bool isvalid(string s) {
    stack<char> mtstack;
    for(int i = 0; i < strlen(s); i++) {
        if(isleft(s[i])) {
            mystack.push(s[i]);
        }else{
            if(mystack.empty() || (mystack.top() != s[i] - 1 && mystack.top() != s[i] - 2)) {
                return false;
            }
            mystack.pop();
        }
    }
    return mystack.empty();
}

bool isleft(char c) {
    return (c == '(' || c == '[' || c == '{');
}

int main () {
    char str[500];
    cin >> str;
    return 0;
}
