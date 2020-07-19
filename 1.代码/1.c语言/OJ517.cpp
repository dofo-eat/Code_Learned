/*************************************************************************
	> File Name: OJ517.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月19日 星期日 13时48分24秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int check(int x, int y, int z) {
    if (x > y) {
        swap(x, y);
    }
    if (y > z) {
        swap(y, z);
    }
    if (x + y > z) return 1;
    return 0;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i < n / 2; i++) {
        int x = (n - i) / 2;
        for (int j = i; j <= x; j++) {
            int y = n - i - j;
            if (check(i, j, y)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
 


