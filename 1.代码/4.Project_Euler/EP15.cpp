/*************************************************************************
	> File Name: EP15.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月28日 星期六 15时39分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    long long int m = 40, n = 20, ans = 1;
    while(m != 20 || n) {
        if(m != 20) ans *= (m--);
        if(n != 0 && ans % n == 0) ans /= (n--);
    }
    cout << ans << endl;
    return 0;
}
