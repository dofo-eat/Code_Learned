/*************************************************************************
	> File Name: 11.test.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月24日 星期日 19时50分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a = n / 10;
    int b = n % 10;
    int ans = b * 10 + a;
    cout << ans << endl;
}
