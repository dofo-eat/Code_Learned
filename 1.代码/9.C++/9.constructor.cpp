/*************************************************************************
	> File Name: 9.constructor.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月26日 星期日 18时15分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
//默认构造
/*class People {
public:
    People() {
        arr = new int[10];
        cout << "default constructor" << endl;
    }
    ~People() {
        delete arr;
        cout << "destructor" << endl;
    }
    int *arr;
};

int main() {
    People a;
    a.arr[9] = 18;
        cout << "hello world" << endl;
    return 0;
}*/

//有参数构造
/*
class People {
public:
    People() {}//为了不a报错添加的由参构造函数

    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(int x) {
        cout << "int param constructor" << endl;
        this->x = x ;
    }
    ~People() {
        cout << "destructor" << endl;
    }
    string name;
    int x;
};

int main() {
    People b("hahahah");
    People a = string("hai");
    People c(543);
    People d = 678;
    cout << a.name << endl;
    cout << b.name << endl;
    cout << c.x << endl;
    cout << d.x << endl;
    //可以进行简单的转
    c = 987;
    cout << c.x << endl;
    cout << "hello world" << endl;
}*/

//拷贝构造


class People {
    //
    //People() = default;
    //People() = delete;
public:
    People() {}//为了不a报错添加的由参构造函数

    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(int x) {
        cout << "int param constructor" << endl;
        this->x = x ;
    }
    //拷贝构造函数
    People (const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
        this->x = a.x;
    }

    ~People() {
        cout << "destructor" << endl;
    }
    string name;
    int x;
};

void incr(int &a) {
    a += 1;
    return ;
}

//转换构造函数的其他用途

int add(People a, People b) {
    return a.x + b.x;
}

int main() {
    cout << add(4, 5) << endl;
    int n = 7;
    incr(n);
    cout << n << endl;
    People a = string("hai");
    People e = a;
    cout << e.name << endl;
    cout << e.x << endl;
    People c(543);
    c = a;
    cout << c.x << endl;
}
