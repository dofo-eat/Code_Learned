/*************************************************************************
	> File Name: 383.赎金信.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 19时17分46秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    bool canConstruct(string r, string m) {
        int code[256] = {0};
        for (int i = 0; m[i]; i++) code[m[i]] += 1;
        for (int i = 0; r[i]; i++) {
            if (code[r[i]] == 0) return false;
            code[r[i]]--;
        }
        return true;
    }
};
