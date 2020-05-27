/*************************************************************************
	> File Name: 15.test.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月26日 星期二 17时27分38秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define MAX_N 10000

struct Data{
    int val, data;
} a[MAX_N + 5];

bool cmp(const Data&a, const Data &b) {
    return a.data < b.data;
}

typedef pair<int, int> PII;
set<PII> s;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].val >> a[i].data;
    }
    sort(a, a + n, cmp);
    for(inr i = 0; i <n; i++) {
        if(s.size() < a[i].data) {
            //当前物品小于过期天数
            s.insert(PII(a[i].val, i));
        } else(s.begin()->first < a[i].val) {
            s.erase(s.begin());
            s,insert(PII(a[i].val, i));
        }
    }
    int ans = 0;
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        ans += iter(first);
    }
    cout << ans << endl;
    return 0;
}
