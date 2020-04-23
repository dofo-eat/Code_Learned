/*************************************************************************
	> File Name: 3.十六进制转十进制.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月22日 星期三 17时31分43秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main () {
    string str1, s2;
    cin >> str1;
    for(int i = 0; i < str1.length(); i++) {
        switch(str1[i]) {
           case '0':s2+="0000";break;
           case '1':s2+="0001";break;
           case '2':s2+="0010";break;
           case '3':s2+="0011";break;
           case '4':s2+="0100";break;
           case '5':s2+="0101";break;
           case '6':s2+="0110";break;
           case '7':s2+="0111";break;
           case '8':s2+="1000";break;
           case '9':s2+="1001";break;
           case 'A':s2+="1010";break;
           case 'B':s2+="1011";break;
           case 'C':s2+="1100";break;
           case 'D':s2+="1101";break;
           case 'E':s2+="1110";break;
           case 'F':s2+="1111";break;
           default:break;
        }
    }
    long long int num = 0;
    for(int i = 0; i < s2.length(); i++) {
        num = num * 2 + (s2[i] - '0');
    }
    cout << num << endl;
    return 0;
}
