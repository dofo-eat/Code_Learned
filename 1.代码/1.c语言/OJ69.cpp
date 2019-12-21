/*************************************************************************
	> File Name: OJ69.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月18日 星期三 20时58分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int mon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y, m, d;
    cin >> y >> m >> d;
    if(m < 0 && d < 0) {
        cout << No << endl;
    }else if(m == 2) {
        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            mon[2]= 29;
        }
    } else if(day <= mon[m]) {
        
    }
    return 0;
}
