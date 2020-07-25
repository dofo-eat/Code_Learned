/*************************************************************************
	> File Name: 8.class.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月25日 星期六 16时19分57秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
//默认private
class People {
    friend int main();
    int x, y;
    //声明
public:
    void set(int x);
    void say();
};

//默认public
struct People2 {
    int x, y;
};

void People::set(int x) {
    cout << "set function:" << this << endl;
    this->x = x;
    return ;
}

void People::say() {
    cout << x << " " << y << endl;
    return;
}

int main() {
    People a;
    cout << "a function ；" << &a << endl;
    People2 b;
    a.y = 18432;
    a.set(3);
    b.x = 4;
    a.say();
    cout << b.x << endl;
    cout << a.y << endl;
    return 0;
}
