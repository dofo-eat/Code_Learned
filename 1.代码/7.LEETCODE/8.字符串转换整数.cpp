/*************************************************************************
	> File Name: 8.字符串转换整数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月19日 星期二 19时49分27秒
 ************************************************************************/
class Solution {
public:
    int myAtoi(string str) {
        int flag = 1,  num = 0, i = 0;//i位置 
        int pre_num = 0;
        while(str[i] == ' ' i++;
        if(str[i] == '-') flag = -1, i++;
        while(str[i]) 『
        if(str[i] <'0' || str[i] > '9') break;
        pre_num = num;
        num = num * 10 + (str[i] - '0');
        if(num / 10 != pre_num) {
            return flag == 1 ? INT_MAX : INT_MIN;
        }
    }
    return num;
};
