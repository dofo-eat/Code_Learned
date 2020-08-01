/*************************************************************************
	> File Name: 18.菱形继承.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月01日 星期六 15时13分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct A {
    int x;
};
struct B :virtual public A {
    void set(int x) {
        //更改的是A的X值
        this->x = x;
        cout << "set:" << &this->x << endl;
    }
};
//virtual 合并有可能产生冗余的父类
struct C :virtual public A {
//读取x
    int get() {
        cout << "get:" << &this->x << endl;
        return this->x;
    }
};
struct D :public B, public C {
    
};

int main() {
    D d;
    d.set(9973);
    //输出的结果不是9973
    cout << d.get() << endl;
    return 0;
}
