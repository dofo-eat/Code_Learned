/*************************************************************************
	> File Name: 19.多太基础.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月01日 星期六 15时56分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public:
    //加上virtual 就可以跟着对象走
    virtual void run() {
        cout << "I don know" << endl;
    }
};

class Cat : public Animal {
public:
    //加不加override之后只是把让一些错误在运行时候的bug暴洛在运行时器
    void run() override{
        //判断事不是真正的重载了run
        cout << "I can run with four legs" << endl;
    }
};

class A {
public:
    int x;
    virtual void run(int x) {
        //this 是一个隐形参数
        cout << this << endl;
        cout << "class A : I can say" << x << endl;
    }
    virtual void run1() {}
};

typedef void (*func)(int);

/*A retA () {
    A temp_a("hello world");
    retA temp_a;
}*/

class Base {
public:
    Base() {
        cout << "Base constructoe" << endl;
        this->x = new int;
    }
    virtual ~Base() {
        cout << "Base destructoe" << endl;
        delete this->x;
    }
private:
    int *x;
};

class Base_A :public Base {
public:
    Base_A() {
        cout << "Base_A constructoe" << endl;
        this->y = new int;
    }
    ~Base_A() {
        cout << "Base_A destructoe" << endl;
        delete this->y;
    }
private:
    int *y;
};

int main () {
    Base *ba = new Base_A();
    delete ba;
    //不加虚函数输出4
    //加上虚函数的之后就4 + 8 但是要存储整数，所以16
    cout << sizeof(A) << endl;
    A temp_a;
    ((func **)(&temp_a))[0][0](6);
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
}
