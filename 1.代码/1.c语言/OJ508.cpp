/*************************************************************************
	> File Name: OJ508.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月13日 星期三 19时14分40秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int n, num[1005], ans;

int main () {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for(int i = n - 1; i >= 0; i -= 2) {
        if(i == 0) {
            ans += num[0];//一个
            break;
        }
        if(i == 1) {
            ans += num[1];//剩两人
            break;
        }
        if(i == 2) {
            ans += num[0] + num[1] + num[2];
            break;
        }
        ans += min(num[1] + num[0] + num[i] + num[1], num[i] + num[0] + num[i - 1] + num[0]);
    }
    cout << ans << endl;
    return 0;
}
