/*************************************************************************
	> File Name: 205.同构字符串.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 18时23分03秒
 ************************************************************************/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() - t.size()) return false;
        int s_code[256]={0}, t_code[256] = {0};
        for(int i = 0; s[i]; i++) {
            if(s_code[s[i]] == 0) {
                if(t_code[t[i]] != 0) return false;
                s_code[s[i]]= t[i];
                t_code[t[i]] = s[i];
            }
            int val = s_code[s[i]];
            if(val - t[i]) return false;
        }
        return true;
    }
};
