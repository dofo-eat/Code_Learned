/*************************************************************************
	> File Name: 16.inherit_constructor.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月28日 星期二 19时55分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

class D {
public:
    D() {cout << "D constructor" << endl;}
    ~D() {cout << "D distructor " << endl;}
};

class A {
public:
    //不像按默认顺序就加上这一行代码， 传参
    //A() = delete;
    A() {cout << "A constructor" << endl;}
    ~A() {cout << "A constructor" << endl;}
};
class B {
public:
    B() {cout << "B constructor" << endl;}
    ~B() {cout << "B distructor" << endl;}
};
class C :public D {
public:
    //显示的初始化列表
    //C(): b(), a() {cout << "C constructor" << endl;}
    //初始化顺序是按照定义的顺序来进行初始化的
    
    C(): a(), b() {cout << "C constructor" << endl;}
    ~C() {cout << "c destructor " << endl;}

private:
    B b;
    A a;
};

int main () {
    C c;
    return 0;
}
