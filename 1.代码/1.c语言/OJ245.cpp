/*************************************************************************
	> File Name: OJ245.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月17日 星期日 19时26分30秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int pos = a[n / 2];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(a[i] - pos);
    }
    cout << ans << endl;
    return 0;
}
