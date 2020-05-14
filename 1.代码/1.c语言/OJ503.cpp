/*************************************************************************
	> File Name: OJ503.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月13日 星期三 18时02分01秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int w, n;
int a[30005];

int main() {
    cin >> w >> n;
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == 0) continue;
        sum++;
        for(int j = i - 1; j >= 0; j--) {
            if(a[j] && a[i] + a[j] <= w) {
                a[j] = 0;
                break;
            }
        }
        //sum++;
    }
    cout << sum << endl;
    return 0;
}
