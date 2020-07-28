/*************************************************************************
	> File Name: 12.operator.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月27日 星期一 18时45分29秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

namespace haizei {
//勒内重载
class istream {
public :
    istream &operator>>(int &n) {
        std::cin >> n;
        return *this;
    }
private:

};

class ostream {
public :        
    ostream &operator<<(int &n) {
        std::cout << n;
        return *this;
    }
    //传入的不可意修改
    ostream &operator<<(const char *msg) {
        std::cout << msg;
        return *this;
    }
private:

};
    
istream cin;
ostream cout;
};

//类外重载
//不能改优先级
//&z引用
haizei::ostream &operator<<(haizei::ostream &out, double &z) {
    std::cout << z;
    return out;
}

//a不只能绑定到一个变量上， 还能绑定到一个常量上
ostream &operator+(ostream &out, const int &a) {
    std::cout << a;
    return out;
}

int main() {
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n << " " << m << "\n";
    double k = 5.6;
    haizei::cout << k << "\n";
    cout + 8 +  9 +  10;
    return 0;
}
