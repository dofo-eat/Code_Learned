/*************************************************************************
	> File Name: 165.比较版本号.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 18时14分11秒
 ************************************************************************/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (version1[i] || version2[j]) {
            int val1 = 0;
            int val2 = 0;
            while (version1[i] && version1[i] <= '9' && version1[i] >= '0') {
                val1 = val1 * 10 + version1[i] - '0';
                i++;
            }
            while (version2[j] && version2[j] <= '9' && version2[j] >= '0') {
                val2 = val2 * 10 + version2[j] - '0';
                j++;
            }
            if (val1 - val2) return val1 > val2 ? 1 : -1;
            if (version1[i]) ++i;
            if (version2[j]) ++j;
        }
        return 0;
    }
};
