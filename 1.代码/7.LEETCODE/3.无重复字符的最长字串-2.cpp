/*************************************************************************
	> File Name: 3.无重复字符的最长字串-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月16日 星期六 20时36分13秒
 ************************************************************************/
//记录每一种子夫最后出现的位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ind[256] = {0};
        int l = 0, ans = 0;
        for(int i = 0; s[i]; i++) {
            l += 1;
            l = min(l, (i + 1) - ind[s[i]]);
            ind[s[i]] = i + 1;
            ans = max(ans, l);
        }
        return ans;
    }
};
