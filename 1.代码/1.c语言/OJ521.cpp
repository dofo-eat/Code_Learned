/*************************************************************************
	> File Name: OJ521.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 17时52分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, r, ans, num[35], pri[3000005] = {1,1};

void func(int s, int sum, int deep) {
    if(deep == r) {
        if(pri[sum] == 0) ans++;
        return ;
    }
    for(int i = s; i <= n -r + deep; i++) {
        sum += num[i];
        func(i +1, sum, deep + 1);
        sum -= num[i];
    }
}

int main() {
    cin >> n >> r;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for(int i = 2;i * i <=3000005; i++) {
        if(pri[i] == 0) {
            for(int j = 2; i * j<= 3000005; j++) {
                pri[i * j] = 1;
            }
        }
    }
    func(0, 0, 0);
    cout << ans << endl;
    return 0;
}
