/*************************************************************************
	> File Name: 344.翻转字符串.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 19时12分23秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < j;i++, j--) {
            swap(s[i], s[j]);
        }
        return ;
    }
};
