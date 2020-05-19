/*************************************************************************
	> File Name: 58.最后一个单词的长度.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月19日 星期二 20时53分34秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s == "") return 0;
        int p1 = s.size() - 1, p2;
        while (p1 >= 0 && s[p1] == ' ') --p1;
        p2 = p1;
        while (p2 >= 0 && s[p2] != ' ') --p2;
        return p1 - p2;
    }
};
