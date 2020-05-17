/*************************************************************************
	> File Name: 3.无重复字符的最长字串.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月16日 星期六 20时35分44秒
 ************************************************************************/
class Solution {
public:
    bool check(string &s, int l) {
        int cnt = 0;
        int arr[256] = {0};
        for(int i = 0; s[i]; i++) {
            arr[s[i]] += 1;
            if(arr[s[i]] == 1) cnt += 1;
            if(i >= l) {
                arr[s[i - l]] -= 1;
                if(arr[s[i - l]] == 0) cnt -= 1;
            }
            if(cnt == l) return 1;
        }
        return 0;
    }

    int bs(string &s, int l, int r) {
        if(l == r) return l;
        int mid = (l + r + 1) >> 1;
        if(check(s, mid)) return bs(s, mid, r);
        return bs(s, l, mid - 1);
    }

    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        return bs(s, 0, s.size() ) ;
    }
};
