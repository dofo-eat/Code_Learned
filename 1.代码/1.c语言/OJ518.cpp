/*************************************************************************
	> File Name: OJ518.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月19日 星期日 14时57分16秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, num = 0, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        num += i;
        sum += i * i;
        if(num == n) {
            cout << sum << endl;
            return 0;
        }
        if((n - num) < i) {
            sum += (n - num) * (i + 1);
            cout << sum << endl;
            return 0;
        }
    }
    return 0;
}
