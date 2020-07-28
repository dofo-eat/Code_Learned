/*************************************************************************
	> File Name: 13.operator-3.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月27日 星期一 20时04分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    int x, y;
};

class B {
public:
    //B() : obj(nullptr) {
    B():obj(){ 
    arr = new int[10];
        arr[3] = 9973;
    }
    B(A* obj):B() {
       this->obj = obj; 
    } 
    int operator()(int a, int b) {
        return a + b;
    }
    int &operator[](int ind) {
        return arr[ind];
    }
    void operator[](const char *msg) {
        cout << msg << endl;
        return;
    }
    //返回A类地址
    A *operator->() {
        return obj;
    }
    ~B() {
        delete arr;
    }
private: 
    int *arr;
    A *obj;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "A(" << a.x << "," << a.y << ")";
    return out;
}
//(),  [],  （间接引用）-> 赋值运算符只能在类内重载
//a.x  sizeof 三木运算， a.*func(),成员指针， ：运算符不能重载
int main() {
    B add;
    //能后像函数一样调用的叫做函数对象
    cout << add(3, 4) << endl;
    //像对相关值进行改变， 就是使用引用
    add[3] = 8876;
    //数组对象
    cout << add[3] << endl;
    add["hello world"];
    A a;
    a.x = 67, a.y = 99;
    B p = &a;
    //值针对象
    cout << p->x << " " << p->y << endl;
    return 0;
}
