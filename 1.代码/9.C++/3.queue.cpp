/*************************************************************************
	> File Name: 3.queue.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月21日 星期二 19时59分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include <queue>
using namespace std;

int main() {
    int op, val;
    queue<int> q;
    while (cin >> op >> val) {
        switch(op) {
            case 1: q.push(val); break;
            case 2: q.pop(); break;
            case 3 :cout << q.front() << endl; break;
        }
        printf("queue size: &lu, empty : %s\n", q.size(), q.empty() ? "true" : "false");
    }
    return 0;
}
