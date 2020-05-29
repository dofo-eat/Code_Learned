/*************************************************************************
	> File Name: OJ41.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月29日 星期五 11时55分06秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX_N 1000

struct BigInt : public vector<int> {
    BigInt(int x = 0){
        push_back(x);
        normal();
    }

    BigInt operator*(int x) {
        BigInt ret(*this);
        for (int i = 0; i < ret.size(); i++) ret[i] *= x;
        ret.normal();
        return ret;
    }

    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        for  (int i = 0; i < a.size(); i++) {
            if (i < ret.size()) ret[i] += a[i];
            else ret.push_back(a[i]);
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

BigInt f[MAX_N + 5];


ostream &operator<<(ostream &out, const BigInt & a) {
    for (int i = a.size() - 1; i >= 0; --i) {
        out << a[i];
    }
    return out;
}

int main() {
    int n, k;
    cin >> n >> k;
    f[1] = k;
    f[2] = (k - 1) * k;
    f[3] = k * (k - 1) * (k - 2);
    for (int i = 4; i <= n; i++) {
        f[i] = f[i - 1] * (k - 2) + f[i - 2] * (k - 1);
    }
    cout << f[n] << endl;
    return 0;
}

