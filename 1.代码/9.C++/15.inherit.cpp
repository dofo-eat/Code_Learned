/*************************************************************************
	> File Name: 15.inherit.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月28日 星期二 19时28分22秒
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

class Animal {
public :
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << "my name is : " << __name << ", my age is : " << age << endl;
    }

protected:
    string __name;

private:
    int age;
};

class Cat : public Animal {
public :
    Cat() = delete;
    Cat(string name, int age) : Animal(name, age) {}
};

class Bat : protected Animal {
public :
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age) {}
    void say() {
        this->Animal::say();
        cout << "class Bat : " << __name << endl;
        //cout << "class Bat : " << age << endl;
        return ;
    }
};

int main() {
    Cat a("kitty", 29);
    a.say();
    Bat b("hug", 16384);
    b.say();
    return 0;
}
