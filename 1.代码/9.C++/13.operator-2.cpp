/*************************************************************************
	> File Name: 13.operator-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月27日 星期一 19时20分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public: 
    //:后面的初始化列表
    Point() : __x(0), __y(0){}
    Point(int x, int y):__x(x), __y(y) {}
    int x() const{return __x;}
    int y() const{return __y;}
    
    Point operator+(const Point &a) {
        return Point(x() + a.x(), y() + a.y());
    }

    Point operator+= (const Point &a) {
        __x += a.x();
        __y += a.y();
        return *this;
    }
    //前++
    Point operator++() {
        __x += 1;
        __y += 1;
        return *this;
    }
    //后++
    Point operator++(int) {
        //需要百之前的拷贝下来
        Point temp(*this);
        __x += 1;
        __y += 1;
        //为什么不能返回引用， 因为temp的生存周期只在这里
        return temp;
    }

private:
    int __x, __y;
};
//const 智能调用const
ostream &operator<<(ostream &out, const Point &a) {
    out <<  "Point (" << a.x() << "," << a.y() << ")";
}

int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    //没有重载<<
    //cout << a << " " << b << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a + b << endl;
    cout << "pre incr :" << ++(c += b) <<endl;
    cout << "after incr:" << c++ <<endl;
    (c += b)++;
    cout << c << endl;
    int n = 6, m = 7;
    (n += m)++;
    cout << n << endl;
    return 0;
}
