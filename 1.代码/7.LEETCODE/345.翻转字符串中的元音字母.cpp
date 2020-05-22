/*************************************************************************
	> File Name: 345.翻转字符串中的元音字母.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 19时13分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
ass Solution {
public:
    bool is_valid(char ch) {
        if (ch < 97) ch += 32;
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !is_valid(s[i])) ++i;
            while (i < j && !is_valid(s[j])) --j;
            if (i >= j) break;
            swap(s[i], s[j]);
        }
        return s;
    }
};
