/*************************************************************************
	> File Name: 125.验证回文串.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月19日 星期二 21时00分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    bool isAlpha(char ch) {
        return ch <= 'z' && ch >= 'a';
    }
    bool isDigit(char ch) {
        return ch <= '9' && ch >= '0';
    }
    bool isPalindrome(string s) {
        int p1 = 0, p2 = s.size() - 1;
        for (int i = 0; s[i]; i++) {
            if (s[i] <= 'Z' && s[i] >= 'A') s[i] += 32;
        }
        while (p1 < p2) {
            while (p1 < s.size() && !isAlpha(s[p1]) && !isDigit(s[p1])) ++p1;
            while (p2 >= 0 && !isAlpha(s[p2]) && !isDigit(s[p2])) --p2;
            if (p1 >= p2) break;
            if (s[p1] != s[p2]) return false;
            p1++, p2--;
        }
        return true;
    }
};
