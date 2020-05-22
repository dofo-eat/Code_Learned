/*************************************************************************
	> File Name: 165.比较版本号-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 18时21分43秒
 ************************************************************************/
ass Solution {
public:
    int getNext(string &str, int i , int &val) {
        val = 0;
         while (str[i] && str[i] <= '9' && str[i] >= '0') {
                val = val * 10 + str[i] - '0';
                i++;
            }
            if(str[i]) i++;
        return i;
    }
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (version1[i] || version2[j]) {
            int val1 = 0;
            int val2 = 0;
            i = getNext(version1, i, val1);
            j = getNext(version2, j, val2);
            if (val1 - val2) return val1 > val2 ? 1 : -1;
        }
        return 0;
    }
};
