/*************************************************************************
	> File Name: 10.class_method-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月26日 星期日 20时12分55秒
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

class Point {
public :
    Point() {
        cout << "constructor : " << this << endl;
        Point::total_cnt += 1;
        seek_cnt = 0;
    }
    Point(const Point &a) : Point() {
        cout << "copy constructor : " << this << endl;
        this->x = a.x;
        this->y = a.y;
    }
    Point(double z) : Point() {
        cout << "convert constructor : " << this << endl;
        this->x = 99, this->y = 99;
    }
    Point(int x, int y) : Point() {
        cout << "param constructor : " << this << endl;
        this->x = x;
        this->y = y;
    }

    void operator=(const Point &a) {
        cout << "operator= : " << this << endl;
        this->x = a.x, this->y = a.y;
        return ;
    }
    void set(int x, int y) {
        this->x = x, this->y = y;
    }
    void seek() const {
        seek_cnt += 1;
       cout << x << " " << y << endl; 
    }
    
    static int T() { return Point::total_cnt; }

    ~Point() {
        cout << "destructor : " << this << endl;
        Point::total_cnt -= 1;
    }
    
private:
    int x, y;
    mq int seek_cnt;
    static int total_cnt;
};

int Point::total_cnt = 0;

void test() {
    Point a;
    cout << Point::T() << endl;
    return ;
}

int main() {
    Point a;
    cout << a.T() << endl;
    test();
    Point b;
    cout << b.T() << endl;
    Point c(3, 4);
    cout << c.T() << endl;
    Point d(3.4);
    cout << d.T() << endl;
    c = 5.6;
    cout << c.T() << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    c.seek();
    d.seek();
    const Point()
    return 0;
}
