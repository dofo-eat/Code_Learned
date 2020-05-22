/*************************************************************************
	> File Name: 387.字符串中第一个唯一字符383.赎金信.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 19时35分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int code[256] = {0};
        for(int i = 0; s[i]; i++) code [s[i]] += 1;
        for(int i = 0; s[i]; i++) if(code[s[i]] == 1) return i;
        return -1;
    }
};
