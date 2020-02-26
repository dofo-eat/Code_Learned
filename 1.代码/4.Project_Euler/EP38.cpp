/*************************************************************************
	> File Name: EP38.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月24日 星期二 18时22分05秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int digit(long long int n) {
    if(n == 0) return 1;
    return floor(log10(n)) + 1;
}

int calc(int x) {
    long long int n = 1, ans = 0;
    while(digit(ans) < 9) {
        ans *= pow(10, digit(x * n));
        ans += n * x;
        n += 1;
    } 
    if(digit(ans) - 9) return 0;
    int num[10] = {1, 0};
    int temp = ans;
    while(temp) {
        if(num[temp % 10]) return 0;
        num[temp % 10] += 1;
        temp /= 10;
    }
    return ans;
}

int main () {
    long long int ans = 0;
    for(int i = 1; i < 10000; i++) {
        int tmp = calc(i);
        if(tmp > ans) ans = tmp;
    }
    cout << ans << endl;
    return 0;
}


