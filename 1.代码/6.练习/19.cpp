/*************************************************************************
	> File Name: 19.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 22时01分28秒
 ************************************************************************/
#include <iostream>

using namespace std;

class A {
public:
    A() {
        x = rand() % 100;
        cout << this << "init x value:" << x << endl;
    }
protected:
    int x;

};


class C : public A {
public :
    int z;
};

class B : public A {
public:  
    void say(B& b) {
        cout << &b << "x value:" << (static_cast<A&>(b)).x << endl;
    }
    //只有在运行的时候的dunamic_cast才可以确定当前的类型
    void say(C& c) {
        //没有办法在编译的时候确定当前的类型和外部的类型时一样的
        cout << &b << "x value:" << (static_cast<A&>(c)).x << endl;
    }
};


int main() {
    //子类的地址转化父类的指针大小不一致；
    //所以要使用的话， 需要转化是单一的子类的对象
   // A *arr = new B[10];
    //这种时可以的
    A *arr = new B();

    //arr[0] = 1;
    //delete[] arr;
    B b1, b2;
    b1.say(b2);
    return 0;
}
