/*************************************************************************
	> File Name: OJ41.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月26日 星期日 20时48分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

#define MAX_N 1000

struct Bigint :public vector<int> {
    Bigint(int x) {
       push_back(x);//倒叙存储
        normal();
    }
    Bigint operator*(int x) {
        Bigint ret(*this);
        for(int i = 0; i < ret.size(); i++) ret[i] *= x;
        ret.normal();
        return ret;
    }
    Bigint operator+(const Bigint &a) {
        Bigint ret(*this);
        for(int i = 0; i < a.size(); i++) {
            if(i < ret.size()) ret[i] += a[i];
            else ret.push_back(a[i]);
        }
    }

    void normal () {
        for(int i = 0; i < size(); i++) {
            if(at(i) < 10) continue;
            if(i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

Bigint f[MAX_N + 5];

ostream &operator<<(ostream &out, const Bigint &a) {
    for(int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main () {
    int n,k;
    cin >> n >> k;
    f[1] = k;
    f[2] =(k - 1) * k;
    f[3] = k * (k - 1) * (k - 2);
    for(int i = 4; i <= n; i++) {
        f[i] = f[i - 1] * (k -2) + f[i -2] * (k - 1);
    }
    cout << f[n] << endl;
    return 0;
}
