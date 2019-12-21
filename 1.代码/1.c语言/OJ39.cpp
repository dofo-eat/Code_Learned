/*************************************************************************
	> File Name: OJ39.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月18日 星期三 20时38分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int begin, n, a = 0;
    cin >> begin >> n;
    for(int i = begin; ; i++) {
        if(i >= 0 && i % 2 == 0) {
            a++;
            if(a <= n) {
                cout << i << endl;
            }
        }
    }
    return 0;
}
