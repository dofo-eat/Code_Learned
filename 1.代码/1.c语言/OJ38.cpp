/*************************************************************************
	> File Name: OJ38.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月28日 星期二 16时51分09秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

struct Bigint:vector<int> {
    Bigint(int x) {
        push_back(x);
        normal();
    }
    Bigint operator+(const Bigint &b) {
        Bigint ret = *this;
        for(int i = 0; i < b.size(); i++) {
            if(i < ret.size()) {
                ret[i] += b[i];
            } else {
                ret.push_back(b[i]);
            }
        }
        ret.normal();
        return ret;
    }
    void normal() {
        for(int i = 0; i < size(); i++) {
            if(at(i) < 10) continue;
            if(i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

ostream &operator<<(ostream &out, const Bigint &a) {
    for(int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    Bigint a = 1, b = 1, c= 0;
    cin >> n;
    while(n--) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << a << endl;
    return 0;
}
