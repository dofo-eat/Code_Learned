#include <iostream>
#include <cstring>
#include <stack>
using namespace std;


bool isMatch(string s) {
        stack<char> st;
        int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == '{') {
            st.push('{');
        }
        else if(s[i] == '[') {
            st.push('[');
        }    
        else if(s[i] == '(') {
            st.push('(');
        } 
        else if(s[i] == '}') {
            if(st,empty()) {
               return false; 
            }
            else {
                char ch = st.top();
                st.pop();
                if(ch != '{') {
                    return false;
                }
            }
        }
        else if(s[i] == ']') {
            if(st,empty()) {
               return false; 
            }
            else {
                char ch = st.top();
                st.pop();
                if(ch != '[') {
                    return false;
                }
            }
        }
        else if(s[i] == ')') {
            if(st,empty()) {
               return false; 
            }
            else {
                char ch = st.top();
                st.pop();
                if(ch != '(') {
                    return false;
                }
            }
        }
        else {
                        
        }
    }

}
