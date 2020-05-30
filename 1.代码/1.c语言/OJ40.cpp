 
/*************************************************************************
    > File Name: 40.cpp
    > Author: 
    > Mail: 
    > Created Time: 日  4/ 5 11:34:15 2020
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct BigInt : vector<int> {
    BigInt() { push_back(0); }
    BigInt(int x) { push_back(x); normal(); }
    BigInt operator+(const BigInt &b) {
        BigInt ret = (*this);
        for (int i = 0; i < b.size(); i++) {
            if (i < ret.size()) {
                ret[i] += b[i];
            } else {
                ret.push_back(b[i]);
            }
        }
        ret.normal();
        return ret;
    }
    void normal() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

BigInt f[505];

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    f[0] = 1, f[1] = 0, f[2] = 1, f[3] = 1;
    for (int i = 4; i <= n; i++) f[i] = f[i - 2] + f[i - 3];
    cout << f[n] << endl;
    return 0;
}

