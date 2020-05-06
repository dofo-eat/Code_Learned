/*************************************************************************
	> File Name: OJ587.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 18时08分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int n, a, b, c, sum = 0;
    cin >> n >> a >> b >> c;
    if(a > b) sum++;
    if(b > c) sum++;
    if(c > a) sum++;
    if(sum == 2) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}
