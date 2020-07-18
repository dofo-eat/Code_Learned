/*************************************************************************
	> File Name: OJ517.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月18日 星期六 13时55分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i < n / 2; i++) {
        for(int j = 1; j <= 10; j++) {
            for(int k = 1; k <= 10; k++) {
                if(i + j + k == 10 && ((i + j) > k) && ((i - j) < k)) {
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
