/*************************************************************************
	> File Name: OJ287.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月23日 星期四 18时57分08秒
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;

typedef pair<int, int> PII;

int main() {
    int n, a, t = 0;
    //t代表时间戳, 保证数据不会重复
    cin >> n;
    set<PII> s;
    for(int i = 0; i < n; i++) {
        cin >> a;
        s.insert(PII(a, t++));
    }
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        sum += a + b;
        s.insert(PII(a + b, t++));
    }
    cout << sum << endl;
    return 0;
}
