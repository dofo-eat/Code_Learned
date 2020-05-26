/*************************************************************************
	> File Name: OJ573.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月25日 星期一 18时59分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct node {
    int raw, now, num;
    bool operator< (const node & b) const {
        if(now == b.now) {
            return num > b.num;
        }
        return now > b.now;
    }
};

int main() {
    priority_queue<node> que;
    string temp;
    while(cin >> temp) {
        if(temp == "#") break;
        int num, raw;
        cin >> num >> raw;
        que.push({raw, raw, num});
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        node t = que.top();
        que.pop();
        cout << t.num << endl;
        t.now += t.raw;
        que.push(t);
    }
}
