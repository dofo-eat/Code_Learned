/*************************************************************************
	> File Name: OJ378.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月07日 星期五 14时13分16秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

bool isValid(char * s){
    int len = strlen(s), top = -1, flag = 1;
    char *stack = (char *)malloc(sizeof(char) *len);
    while(s[0]) {
        switch(s[0]) {
            case '(':stack[++top] = s[0];break;
            case '[':stack[++top] = s[0];break;
            case '{':stack[++top] = s[0];break;
            case')':flag = (top != -1 && stack[top--] == '(');break;
            case']':flag = (top != -1 && stack[top--] == '[');break;
            case'}':flag = (top != -1 && stack[top--] == '{');break;
        }
        if(flag == 0) break;
        s++;
    }
    free(stack);
    if (flag &&top == -1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main () {
    char str[500];
    cin >> str;
    isValid(str);
    return 0;
}
