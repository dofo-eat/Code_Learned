/*************************************************************************
	> File Name: 26.使用move实现vector.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月17日 星期一 15时44分15秒
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <utility>
#include <cstring>
using namespace std;
class Element {
private:
    int number;
public:
    Element() :number(0) {
        cout << "ctor" << endl;
    }
    Element(int num):number(num) {
        cout << "ctor" << endl;
    }
    Element(const Element& e):number(e.number) {
        cout << "copy ctor" << endl;
    }
    Element(Element&& e):number(e.number) {
        cout << "right value ctor" << endl;
    }
    ~Element() {
        cout << "dtor" << endl;
    }
    void operator=(const Element& item) {
        number = item.number;
    }
    bool operator==(const Element& item) {
        return (number == item.number);
    }
    void operator()() {
        cout << number ;
    }
    int GetNumber() {
        return number;
    }
};
template<typename T>
class Vector {
private:
    T* items;
    int count;
public:
    Vector() :count{ 0 }, items{nullptr} {

    }
    Vector(const Vector& vector) :count{vector.count} {
        items = static_cast<T*>(malloc(sizeof(T) * count));
        memcpy(items, vector.items, sizeof(T) * count);
    }
    Vector(Vector&& vector) :count{ vector.count }, items{ vector.items } {
        vector.items = nullptr;
        vector.count = 0;
    }
    ~Vector() {
        Clear();
    }
    T& operator[](int index){
        if (index<0||index>=count) {
            cout<<"invalid index"<<endl;
            return items[0];
        }
        return items[index];
    }
    int returnCount(){
        return count;
    }
    void Clear() {
        if (count == 0) return ;
        for (int i = 0; i < count; i++) {
            items[i].~T();
        }
        free(items);
        items = nullptr;
        count = 0;
        return ;
    }

    void Add(const T& item) {
        T *new_store = (T *)malloc(sizeof(T) * (count + 1));
        for (int i = 0; i < count; i++) {
            new(new_store + i)T(std::move(items[i]));
        }
        new(new_store + count)T(item);
        int pre = count + 1;
        Clear();
        count = pre;
        items = new_store;
        return ;
    }
    bool Insert(const T& item,int index) {
        if (index < 0 || index > count) return false;
        T *new_store = (T *)malloc(sizeof(T) * (count + 1));
        for (int i = count - 1; i >= index; i--) {
            new(new_store + i + 1)T(std::move(items[i]));
        }
        new(new_store + index)T(item);
        for (int i = 0; i < index; i++) {
            new(new_store + i)T(std::move(items[i]));
        }
        int pre = count + 1;
        Clear();
        count = pre;
        items = new_store;
        return true;
    }
    bool Remove(int index) {
        if (index < 0 || index > count) return false;
        T *new_store;
        if (count - 1) new_store = (T *)malloc(sizeof(T) * (count - 1));
        else new_store = nullptr;
        for (int i = 0; i < count; i++) {
            if (i == index) continue;
            if (i < index) new(new_store + i)T(std::move(items[i]));
            if (i > index) new(new_store + i - 1)T(std::move(items[i]));
        }
        int pre = count - 1;
        Clear();
        count = pre;
        items = new_store;
        return true;
    }
    int Contains(const T& item) {
        for (int i = 0; i < count; i++) {
            if (items[i] == item) return i;
        }
        return -1;
    }
};
template<typename T>
void PrintVector(Vector<T>& v){
      int count=v.returnCount();
      for (int i = 0; i < count; i++)
      {
          v[i]();
          cout << " ";
      }
      cout << endl;
}
int main() {
    Vector<Element>v;
    for (int i = 0; i < 4; i++) {
        Element e(i);
        v.Add(e);
    }
    PrintVector(v);
    Element e2(4);
    if (!v.Insert(e2, 10))
    {
        v.Insert(e2, 2);
    }
    PrintVector(v);
    if (!v.Remove(10))
    {
        v.Remove(2);
    }
    PrintVector(v);
    Element e3(1), e4(10);
    cout << v.Contains(e3) << endl;
    cout << v.Contains(e4) << endl;
    Vector<Element>v2(v);
    Vector<Element>v3(move(v2));
    PrintVector(v3);
    v2.Add(e3);
    PrintVector(v2);
    return 0;
}
 
