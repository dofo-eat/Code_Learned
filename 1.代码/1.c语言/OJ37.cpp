/*************************************************************************
	> File Name: OJ37.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月27日 星期一 17时53分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    for(int i = n; i <= m; i++) {
        if(i % 2 != 0 || i % 5 != 0) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
