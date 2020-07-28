/*************************************************************************
	> File Name: 17.inherit_copyconstructor.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月28日 星期二 20时45分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

class A {
public:
    A() {
        cout << "class A constructor" << endl;
        this->x = 0x01020304;

    }
    A(const A &a) {
        cout << "class A copy constructor" <<this<<  endl;
    }
    int x;
};

class B : public A {
public:
    B() {
        this->y = 0x05060708;
        cout << "class B constructor" <<endl;
        
    }

    //拷贝构造需要定义一个单独的显示引用
    //继承的语义信息就是可以b对象看为一个A对象， 就ihiyige对象可以帮钉在她的父类引用上
    //对于一个对象的起始位置不变， 但是看我们需要几个字节就来几个字节的变来嗯
    B(const B &b) : A(b) {
        cout << "class B copy constructor" << this <<endl;
    }
    int y;
};

int main() {
    B b1;
    B b2(b1);
    const char *msg = (const char *)(&b1);
    for(int i = 0; i <= sizeof(B); i++) {
        printf("%X", msg[i]);
    }
    //输出43218765小端机器
    //低位存储在低端
    printf("\n"
        );
    return 0;
}
