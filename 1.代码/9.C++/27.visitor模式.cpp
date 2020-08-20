/*************************************************************************
	> File Name: 27.visitor模式.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月20日 星期四 10时36分37秒
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

class Cat;
class Dog;
class Mouse;
class Bat;

class Animal {
public :
    class IVisitor {
    public :
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(Mouse *) = 0;
        virtual void visit(Bat *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~Animal() {}
};

class Cat : public Animal {
public :
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class Dog : public Animal {
public :
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    
};

class Mouse : public Animal {
public :
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }

};

class Bat : public Animal {
public :
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class AnimalCout : public Animal::IVisitor {
public :
    virtual void visit(Cat *obj) {
        cout << "this is a cat" << endl;
    }
    virtual void visit(Dog *obj) {
        cout << "this is a dog" << endl;
    }
    virtual void visit(Mouse *obj) {
        cout << "this is a mouse" << endl;
    }
    virtual void visit(Bat *obj) {
        cout << "this is a bat" << endl;
    }
};

class AnimalCount : public Animal::IVisitor {
public :
    AnimalCount() : val1(0), val2(0), val3(0), val4(0) {}
    virtual void visit(Cat *obj) {
        val1 += 1;
    }
    virtual void visit(Dog *obj) {
        val2 += 1;
    }
    virtual void visit(Mouse *obj) {
        val3 += 1;
    }
    virtual void visit(Bat *obj) {
        val4 += 1;
    }
    int val1, val2, val3, val4;

};

int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0: arr[i] = new Cat(); break;
            case 1: arr[i] = new Dog(); break;
            case 2: arr[i] = new Mouse(); break;
            case 3: arr[i] = new Bat(); break;
        }
    }
    AnimalCout vis;
    AnimalCount cnt;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
        arr[i]->Accept(&cnt);
    }
    cout << "Cat : " << cnt.val1 << endl;
    cout << "Dog : " << cnt.val2 << endl;
    cout << "Mouse : " << cnt.val3 << endl;
    cout << "Bat : " << cnt.val4 << endl;
    return 0;
}
/*
int main() {
    srand(time(0));
    Animal *arr[10];
    for(int i = 0; i < 10; i++) {
        switch(rand() % 4) {
            case 0:arr[i] = new Cat();break;
            case 1:arr[i] = new Dog();break;
            case 2:arr[i] = new Mouse();break;
            case 3:arr[i] = new Bat();break;
        }
    }
    AnimalCout vis;
    AnimalCout cnt;
    for(int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
        arr[i]->Accept(&cnt);
    }
    cout << "Cat : " << cnt.val << endl; 
    cout << "Cat : " << cnt.val << endl; 
    cout << "Cat : " << cnt.val << endl; 
    cout << "Cat : " << cnt.val << endl; 
    //由一个问题， 就是当我们增加子类的时候， 编译器不会报错， 在大型工程中忘记修改某一段代码， 之后， 在编译通过后域与我们的实现方式不太一样
    //第二个是效率的问题
    for(int i = 0; i < 10; i++) {
        //通过dynamic_cast看它具体是一个什么类
        if(dynamic_cast<Cat *>(arr[i])) {
            cout << "this is a Cat" << endl;
        } else if(dynamic_cast<Dog *>(arr[i])) {
            cout << "this is a Dog";
        } else if(dynamic_cast<Mouse *>(arr[i])) {
            cout << "this is a Mouse" << endl;
        } 
        else if(dynamic_cast<Bat *>(arr[i])) {
            cout << "this is a Bat" << endl;
        }
    }
    return 0;
}*/
