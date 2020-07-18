/*************************************************************************
	> File Name: OJ516.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月18日 星期六 13时20分40秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(str[i] == 'C' && str[j] == 'O' && str[k] == 'W') {
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
