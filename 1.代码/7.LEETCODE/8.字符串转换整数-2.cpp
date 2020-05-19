/*************************************************************************
	> File Name: 8.字符串转换整数-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月19日 星期二 19时49分42秒
 ************************************************************************/
class Solution {
public:
    int myAtoi(string str) {
        int flag = 1, num = 0, i = 0, pre_max = INT_MAX / 10, d = INT_MAX % 10;
        while (str[i] == ' ') ++i;
        if (str[i] == '-') flag = -1, ++i;
        else if (str[i] == '+') flag = 1, ++i;
        while (str[i]) {
            if (str[i] < '0' || str[i] > '9') break;
            if (num > pre_max || 
                (num == pre_max && (str[i] - '0') > d)) {
                return flag == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 + (str[i] - '0');
            i++;
        }
        return num * flag;
    }
};
