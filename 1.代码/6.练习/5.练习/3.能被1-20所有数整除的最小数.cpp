/*************************************************************************
	> File Name: 3.能被1-20所有数整除的最小数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月23日 星期一 00时32分15秒
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return(b ? gcd(b, a % b) : a);
}

int main () {
    int ans = 1;
    for(int i = 1; i < 20; i++) {
        if(ans % i == 0) continue;
        ans *= i / gcd(ans, i);
    }
    cout << ans << endl;
}
