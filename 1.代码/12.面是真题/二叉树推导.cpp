/*************************************************************************
	> File Name: 二叉树推导.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月26日 星期三 15时26分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

string q, z;

void func(int qs, int qe, int zs, int ze) {
    if(qe < qs) return;
    if(qs == qe) {
        cout << q[qs]; return;
    }
    char root = q[qs];
    for(int i = zs; i <= ze; i++) {
        if(z[i] == root) {
            func(qs + 1, (i - zs) + qs, zs, i - 1);
            func(i - zs + qs + 1, qe, i + 1, ze);
            cout << root;
            break;
        }
    }
}

int main() {
    cin >> q >> z;
    func(0, q.size() - 1, 0, z.size() - 1);
    cout << endl;
}
