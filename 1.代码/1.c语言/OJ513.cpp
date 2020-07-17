/*************************************************************************
	> File Name: OJ513.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月17日 星期五 17时02分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

int solve (int m, int t) {
    while(m) {
        if(m % 10 == t) {
            return 1;
            break;
        }
        m /= 10;
    }
    return 0;
}

int main() {
    int m, t;
    cin >> m >> t;
    int sum = m;
    for(int i = 1; i <= m; i++) {
        if(solve(i, t) != 0) {
            sum--;
        }
    }
    cout << sum << endl;
}
