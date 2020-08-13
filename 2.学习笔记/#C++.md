# C++

## 1.auto

* 不能作用在函数定义
* 不能作用在数组上， 
* 作用在编译时能够自行推导
* 不能作用于非静态的成员变量；

~~~c
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

int main() {
    auto a = 123;
    cout << sizeof(a) << endl;
    map<int, int> arr;
    arr[71264716] = 1387183;
    arr[45612] = 712;
    arr[999] = 10000;
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    for (auto x : arr) {
        cout << x.first << ", " << x.second << endl;
    }
    return 0;
}
~~~



## 2.const

* 定义const时， 我们不能对他进行重载， 但是了一定以一个未知的n,来进行输入
* constptr 就不可以， 只能使用在编译期的能够有确定值得 的， 但是不能使用递归

```c
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


constexpr int f(int x) {
    return 3 * x * x + x;
}


class A {
public :
    constexpr A(int x, int y) : x(x), y(y) {}
    int x, y;
};


int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    constexpr int m = f(12);
    cout << m << endl;
    constexpr A a(2, 3);
    cout << a.x << ", " << a.y << endl;
    return 0;
}
```

##  final

* 防治子类对父类方法的重写覆盖
* 防止关键字对他进行继承

```c
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


class A : public map<int, int> {
public :
    virtual void say() {
        cout << "Class A : hello world" << endl;
    }
};


class B final : public A {
public :
    void say() final override {
        cout << "Class B : hello world" << endl;
    }
};


/*class C: public B {
public :
    void say() override {
        cout << "Class C : hello world" << endl;
    }
};*/


int main() {
    A a;
    a[12131] = 1133;
    a[71263812] = 9973;
    for (auto x : a) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
```

## 4 nullptr是没有歧义的空地址

```c
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


int f(int x) {
    cout << "output int value : ";
    cout << x << endl;
    return 0;
}


int f(int *x) {
    cout << "output address : ";
    cout << x << endl;
    return 0;
}


int main() {
    printf("%lld", (long long)nullptr);
    cout << NULL << endl;
    int n = 123, *p = &n;
    f(n);
    f(p);
    f(nullptr);
    f((int)NULL);
    return 0;
}
```

## 5.左值 右值 左值引用 右值引用四个概念

*同样变量， 单一方式 同样的结果

* 左值引用& 右值引用&&
* forWord向前传递   还有move 这两种都是正确的向下传递

```c
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
#define TEST(a, f) { \
    cout << #a <<  " : " << #f << " "; \
    f(a); \
}


void f2(int &x) {
    cout << "left value" << endl;
}


void f2(int &&x) {
    cout << "right value" << endl;
}


void f(int &x) {
    cout << "left value" << endl;
    TEST(x, f2);
}


void f(int &&x) {
    cout << "right value" << endl;
    TEST(move(x), f2);
    TEST(forward<int &&>(x), f2);
}

//把一个右值绑定在左值的情况只有常量左值引用 
int test_func(const int &x) {
	//右值引用 一般是不可以的 
	//int test_func(const int &&x) {
	cout << x << endl;
	return 0;
} 


int main() {
    int a, b = 1, c = 3;
    (++a) = b + c;
    cout << a << endl;
    (a++);
    (a = b) = c;
    cout << a << " " << b << endl;
    int arr[10];
    arr[3] = 12;
    (a += 3) = 67;
    cout << a << endl;
    TEST(a += 3, f);
    TEST(1 + 4, f);
    TEST(b + c, f);
    TEST(a++, f);
    TEST(++a, f);
    //只有强制吧右值转换成左值才可以 
    test_func(move(a));
    return 0;
}
```

move 部分讲解



~~~ c

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

namespace haizei {
class string {
public :
    string() {
        cout << "string : default constructor, " << this << endl;
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) {
        cout << "string : const char constructor, " << this << endl;  
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }
    string(const string &s) {
        cout << "copy constructor, " << this << endl;
        this->__buff_size = s.__buff_size; 
        this->__length = s.__length;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, s.buff);
    }
    string(string &&s) {
        cout << "move constructor, " << this << endl;
        this->__buff_size = s.__buff_size; 
        this->__length = s.__length;
        this->buff = s.buff;
        s.buff = nullptr;
    }
    char &at(int ind) {
        if (ind < 0 || ind >= __length) {
            cout << "String Error : out of range" << endl;
            return __end;
        }
        return this->operator[](ind);
    }
    char &operator[](int ind) {
        return buff[ind];
    }
    const char *c_str() const {
        return buff;
    }
    string operator+(const string &s) {
        cout << "string : operator+, " << this << endl;
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }
    int size() { return this->__length; }
    ~string() {
        cout << "string : destructor, " << this << endl;
        if (this->buff) delete this->buff;
    }

private:
    int __length, __buff_size;
    char *buff;
    char __end;
};

}

ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str();
    return out;
}

int main() {
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = ", harbin.";
    cout << "==== s4 begin ====" << endl;
    haizei::string s4 = s1 + s2 + s3;
    cout << "==== s4 end ====" << endl;
    cout << s1 << endl;
    haizei::string s5 = s4;
    cout << s4 << endl;
    cout << s5 << endl;
    s4[3] = '=';
    cout << s4 << endl;
    cout << s5 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 << endl;
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }
    return 0;
}

~~~

## 二、模板

数据结构：存储任意类型的数据

算法：能够操作任意类型的数据的数据结构



|        | 范式编程       |
| ------ | ---------- |
| 面向过程编程 | 用模板实现函数的过程 |
| 面向对象编程 | 用模板实现类     |

![1596684847399](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\1596684847399.png)

### 实现一个简单的add

~~~c
#include<iostream>
using namespace std;

//还可以用class没有区别 
//template<typename T>
//T add (T a, T b) {
//	return a + b;
//}



template<typename T, typename U>
//让decltype去推导他的返回值类型 
//当T 和 U没有默认构造会报错 
//decltype(T() + U()) add(T a, U b) {
//	return a + b;
//}


auto add (T a, U b) ->decltype(a + b) {
	return a + b;
}  
int main() {
	//这种叫做隐士的推导 
	cout << add(2, 3) << endl;
	cout << add(2.3, 4.3) << endl;
	cout << add(11111111111111, 1111111111111) << endl;
	//把他显示调用 
	cout << add<double>(2.3, 5) << endl;
	//自行推导的 
	cout << add(5, 2.3) << endl; 
	cout << add(-2.3, 5) << endl;  
	return 0;
} 

//cout << max(4, 3) <<endl; STL自带的方法
	//但是cout << max(4.3, 3) << endl; 他默认构造的也是同类型的第一种 add
~~~

### 2,2模板类的实现

~~~ c
#include<iostream>
using namespace std;

namespace haizei{
	template<typename T, typename U>
	auto max(T a, U b)->decltype(a + b) {
		return a > b ? a : b;
	}
	//模板定义在头文件中， 作用在编译阶段， 而宏的时候是在预编译阶段
	//宏只是一个简单的替换， 
	//又因为模板是定义在头文件， 所以可能重定义， 但是冲突的时候，我们在连接阶段， 编译过程中会进行特殊的合并处理 
	//仅限于模板的重复定义
	//这段其实nm命令很好用 
	class  PrintAny {
		public:
		template<typename T>
		void operator()(const T &a) {
			cout << a << endl;
		}
	};
} 

int main() {
	cout << haizei::max(2, 3) << endl;
	cout << haizei::max(2, 3.3) << endl;
	cout << haizei::max(3.3, 5.4) << endl;
	cout << haizei::max('A', 'B') << endl;
	cout << haizei::max('a', 3) << endl;
	haizei::PrintAny print;
	print(123);
	print(45.678);
	print("haizei");
}
~~~

## 2.3模板的特化

~~~ c
#include <iostream>
using namespace std;

template<typename T, typename U>
auto add (T a, U b) ->decltype(a + b) {
	return a + b;
}  
//模板的特化 
template<>
int add(int a, int b) {
	cout << "add int : " << a << " " << b << endl;
} 

int main() {
	add(2, 3); 
	return 0;
}
~~~

### 2.4 偏特化的模板

```c
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


class A {
public :
    A(int x) : x(x) {}
    int x;
};


class B {
public: 
    B(int y) : y(y) {}
    int y;
};


int operator+(const A &a, const B &b) {
    return a.x + b.y;
}


namespace haizei {


template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}


template<>
int add(int a, int b) {
    cout << "add int : "<< a << " " << b << endl;
    return a + b;
}


template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b);
}


template<typename T, typename U>
auto max(T a, U b) -> decltype(a + b) {
    return a < b ? b : a;
}


template<typename T, typename U>
auto min(T a, U b) -> decltype(a + b) {
    return a < b ? a : b;
}


class PrintAny {
public :
    template<typename T>
    void operator()(const T &a) {
        cout << a << endl;
    }
};


template<typename T>
class FoolPrintAny {
public:
    void operator()(const T &a) {
        cout << a << endl;
    }
};


template<>
class FoolPrintAny<int> {
public:
    void operator()(const int &a) {
        cout << "naughty : " << 2 * a << endl;
    }
};


template<typename T>
void printAny(const T &a) {
    cout << a << endl;
    return ;
}


template<typename T, typename ...ARGS>
void printAny(const T &a, ARGS...args) {
    cout << a << " ";
    printAny(args...);
    return ;
}


template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(
        typename ARG<ARGS...>::__type a, 
        typename ARG<ARGS...>::__rest::__type b) {
        return a + b;
    }
};


}


int main() {
    A a(1000);
    B b(645);
    cout << a + b << endl;
    cout << haizei::add(2, 3) << endl;
    cout << haizei::add(2.3, 4.3) << endl;
    cout << haizei::add(2.3, 5) << endl;
    cout << haizei::add(5, 2.3) << endl;
    cout << haizei::add(string("hello"), "hello world") << endl;
    cout << haizei::add(a, b) << endl;
    cout << haizei::max(4, 3) << endl;
    cout << haizei::max(4.3, 3) << endl;
    cout << haizei::min(4, 3) << endl;
    cout << haizei::min(4.3, 3) << endl;
    haizei::PrintAny print;
    print(123);
    print(45678);
    print(3.4);
    print("hello world");
    print("hello haizei");
    print(&a);
    haizei::FoolPrintAny<string> f;
    f("hello world");
    haizei::FoolPrintAny<int> f2;
    f2(123);
    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl;
    cout << haizei::add(p, q) << endl;
    haizei::printAny(123, 34.5, "hello world", &a);
    haizei::Test<int(int, int)> f3;
    cout << f3(3, 4) << endl;
    return 0;
}
```

### 2.5 变参模板

首先实现普通的模板

~~~ c
using namespace std;

template<typename T> 
void print(const T &a) {
	cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
	cout << a << " " ;
	print(args...);
	//证明是变参的变量列表 
	return ;
}

template<typename T, typename ...ARGS>
//帮助进行变参列表展开 
struct ARG {
	typedef T getT;
	//剩余的变参列表 
	typedef ARG<ARGS...> rest;
};

//偏特化 
template<typename T>
struct ARG<T> {
	typedef T getT;
	//代表到了这个是最后一个 
	typedef T finalT;
}; 

//template<typename T, typename ...ARGS>
//class Test {
//public:
//	T operator()(typename ARG<ARGS...>::getT a, typename ARG<ARGS...>::rest::getT b) {
//		return a + b;
//	}
//}; * 1 

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public:
//	T operator()(typename ARG<ARGS...>::getT a, typename ARG<ARGS...>::rest::finalT b) { *2 
	T operator()(typename ARG<ARGS...>::getT a, typename ARG<ARGS...>::rest::getT b) {
		return a + b;
	}
};

int main() {
	print(123, "hello world", 78.8, 'o'); 
	cout <<sizeof(ARG<int, double, float>::getT) << endl;
	cout <<sizeof(ARG<int, double, float>::rest::getT) << endl;
	cout <<sizeof(ARG<int, double, float>::rest::rest::getT) << endl;
	ARG<int, double, float>::getT a = 123;
	ARG<int, double, float>::rest::getT b = 12.3;
	ARG<int, double, float>::rest::rest::getT c = 123.45;
	cout << a << " " << b << " " << c << endl;
//	Test<int, double, float> d;因为int 是返回值类型   * 1 
	Test<int(double, float)> d; 
	cout << d(2.3, 4.5) << endl;
	//实现对于这个的报错提醒 
	//Test<int(double, float, int, int, int)> e; *2
	//改进使用 
//	ARG<4， int, double, int, int, int>::getT; 
	Test<int(int, int, int, int) > e;
	cout << e(1, 2, 3, 4) << endl;
	return 0;
}
~~~

实现第几个参数就用第几个实现

~~~ c
#include <iostream>
using namespace std;

template<typename T>
void print(const T &a) {
    cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}
//方便使用， 0返回当前类型，  
template<int n, typename T, typename ...ARGS>
struct ARG {
	//说明他是一个类型 ， 为n下面的getT 
    typedef typename ARG<n - 1, ARGS...>::getT getT;
    //非0的情况 
    //并且判断有没有finalT 
    typedef ARG<n - 1, ARGS...> N;
};

template<typename T, typename ...ARGS>
//当他是0的时候他可能是一个变参列表 
struct ARG<0, T, ARGS...> {
    typedef T getT;
};

template<typename T>
struct ARG<0, T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
        return a + b;
    }
};

int main() {
    print(123, 23.5, "hello world", 'o');
    Test<int(double, float)> a;
    cout << a(2.3, 4.5) << endl;
//	ARG<2, int, double, float>::getT b = 12.3;
//	Test<int(double, float)> c;
//	cout << c(b, 4.53) <<endl;
	//ARG<3, int, double, float>::getT c = 123.45;
   ARG<4, int, double, int, int, int>::getT d = 123;
   cout << d << endl;
    return 0;
}
~~~

实现变参列表相加求和

~~~ c
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

class A {
public :
    A(int x) : x(x) {}
    int x;
};

class B {
public: 
    B(int y) : y(y) {}
    int y;
};

int operator+(const A &a, const B &b) {
    return a.x + b.y;
}

namespace haizei {

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

template<>
int add(int a, int b) {
    cout << "add int : "<< a << " " << b << endl;
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b);
}

template<typename T, typename U>
auto max(T a, U b) -> decltype(a + b) {
    return a < b ? b : a;
}

template<typename T, typename U>
auto min(T a, U b) -> decltype(a + b) {
    return a < b ? a : b;
}

class PrintAny {
public :
    template<typename T>
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<typename T>
class FoolPrintAny {
public:
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<>
class FoolPrintAny<int> {
public:
    void operator()(const int &a) {
        cout << "naughty : " << 2 * a << endl;
    }
};

template<typename T>
void printAny(const T &a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void printAny(const T &a, ARGS...args) {
    cout << a << " ";
    printAny(args...);
    return ;
}

template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::__type __type;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...> {
    typedef T __type;
};

template<typename T>
struct ARG<0, T> {
    typedef T __type;
    typedef T __final;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(ARGS... args) {
        return add<T>(args...);
    }
private:
    template<typename T1, typename U, typename ...US>
    T1 add(U a, US ...args) {
        return a + add<T1>(args...);
    }
    template<typename T1, typename U>
    T1 add(U a) {
        return a;
    }
};

template<typename T, typename U>
T test_param_func(U a) {
    return T(a * 2);
}

void func2(int (*func)(double)) {
    cout << func(2.3) << endl;
}

template<typename T> struct remove_reference { typedef T type; };
template<typename T> struct remove_reference<T &> { typedef T type; };
template<typename T> struct remove_reference<T &&> { typedef T type; };

template<typename T>
typename remove_reference<T>::type add2(T &&a, T &&b) {
    typename remove_reference<T>::type c = a + b;
    return c;
}

} // end of haizei

int main() {
    int inta = 123, intb = 456;
    cout << haizei::add2(inta, intb) << endl;
    cout << haizei::add2(123, 456) << endl;
    haizei::func2(haizei::test_param_func);
    A a(1000);
    B b(645);
    cout << a + b << endl;
    cout << haizei::add(2, 3) << endl;
    cout << haizei::add(2.3, 4.3) << endl;
    cout << haizei::add(2.3, 5) << endl;
    cout << haizei::add(5, 2.3) << endl;
    cout << haizei::add(string("hello"), "hello world") << endl;
    cout << haizei::add(a, b) << endl;
    cout << haizei::max(4, 3) << endl;
    cout << haizei::max(4.3, 3) << endl;
    cout << haizei::min(4, 3) << endl;
    cout << haizei::min(4.3, 3) << endl;
    haizei::PrintAny print;
    print(123);
    print(45678);
    print(3.4);
    print("hello world");
    print("hello haizei");
    print(&a);
    haizei::FoolPrintAny<string> f;
    f("hello world");
    haizei::FoolPrintAny<int> f2;
    f2(123);
    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl;
    cout << haizei::add(p, q) << endl;
    haizei::printAny(123, 34.5, "hello world", &a);
    haizei::Test<int(int, int)> f3;
    cout << f3(3, 4) << endl;

    haizei::Test<int(int, int, int, int)> f4;
    cout << f4(1, 2, 3, 4) << endl;

    haizei::Test<int(int, int, int, int, int)> f5;
    cout << f5(1, 2, 3, 4, 5) << endl;
    return 0;
}
//包含了部分的引用
~~~

### 2,5 模板参数推导

![1596858461562](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\1596858461562.png)

#### 2.5.1 正常的模板参数推导

* 隐式转换

* 显式转换

* 模板函数作为参数

  ~~~ c
  T test_param_func(U a) {
  	return a * 2;
  }

  void func2(int (*func)(double)) {
  	cout << func(2.3) << endl;
  }
  haizei::func2(hizei::test_param_func);
  ~~~

### 2.5.2 引用折叠

奇数个&代表左值引用

偶数个&代表右值引用

* 在模板中想要传递引用的时候， 只要写上两个引用， 这样你既可以传递左值， 又可以传递右值， 这样的话他就会自己进行推导引用符号&&前面的类型

~~~ c

template<typename T> 
struct remove_reference {
	typedef T type;
};
//偏特化版 如果是引用就变成正常类型 
template<typename T> 
struct remove_reference<T &> {
	typedef T type;
};
//右值引用 
template<typename T> 
struct remove_reference<T &&> {
	typedef T type;
};

template<typename T> 
//不进行更改的时候T是一个引用类型
 
//T add2(T &&a, T &&b) {
typename remove_reference<T>::type add2(T &&a, T &&b) {
	typename  remove_reference<T>::type c = a + b;
	return c;
	//并且不会发生拷贝操作 
}
int inta = 123, intb = 456;
    cout << "传参" << haizei::add2(inta, intb) << endl;
    cout << " 传值"<<haizei::add2(123, 456) << endl;
~~~

* 部分末班参数的实现

~~~ c
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

class A {
public :
    A(int x) : x(x) {}
    int x;
};

class B {
public: 
    B(int y) : y(y) {}
    int y;
};

int operator+(const A &a, const B &b) {
    return a.x + b.y;
}

namespace haizei {

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

template<>
int add(int a, int b) {
    cout << "add int : "<< a << " " << b << endl;
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b);
}

template<typename T, typename U>
auto max(T a, U b) -> decltype(a + b) {
    return a < b ? b : a;
}

template<typename T, typename U>
auto min(T a, U b) -> decltype(a + b) {
    return a < b ? a : b;
}

class PrintAny {
public :
    template<typename T>
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<typename T>
class FoolPrintAny {
public:
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<>
class FoolPrintAny<int> {
public:
    void operator()(const int &a) {
        cout << "naughty : " << 2 * a << endl;
    }
};

template<typename T>
void printAny(const T &a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void printAny(const T &a, ARGS...args) {
    cout << a << " ";
    printAny(args...);
    return ;
}

template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::__type __type;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...> {
    typedef T __type;
};

template<typename T>
struct ARG<0, T> {
    typedef T __type;
    typedef T __final;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(ARGS... args) {
        return add<T>(args...);
    }
private:
    template<typename T1, typename U, typename ...US>
    T1 add(U a, US ...args) {
        return a + add<T1>(args...);
    }
    template<typename T1, typename U>
    T1 add(U a) {
        return a;
    }
};

template<typename T, typename U>
T test_param_func(U a) {
    return T(a * 2);
}

void func2(int (*func)(double)) {
    cout << func(2.3) << endl;
}

template<typename T> struct remove_reference { typedef T type; };
template<typename T> struct remove_reference<T &> { typedef T type; };
template<typename T> struct remove_reference<T &&> { typedef T type; };

//const 
template<typename T> struct add_const { typedef const T type; };
//对于const int单独处理 
template<typename T> struct add_const<const T> { typedef const T type; };

//左值 
template<typename T> struct add_lvalue_referenc { typedef T &type; };
template<typename T> struct add_lvalue_referenc<T &> { typedef T &type; };
template<typename T> struct add_lvalue_referenc<T &&> { typedef T &type; };

//右值 
template<typename T> struct add_rvalue_referenc { typedef T &&type; };
template<typename T> struct add_rvalue_referenc<T &> { typedef T &&type; };
template<typename T> struct add_rvalue_referenc<T &&> { typedef T &&type; };

//指针 
template<typename T> struct remove_pointer { typedef T type; };
template<typename T> struct remove_pointer<T &> { typedef typename remove_pointer<T>::type type; };


template<typename T>
typename remove_reference<T>::type add2(T &&a, T &&b) {
    typename remove_reference<T>::type c = a + b;
    return c;
}
//返回的是右值引用，  
template<typename T>
//一定要传引用  避免发生拷贝行为 
typename add_rvalue_referenc<T>::type move(T &&a) {
	//前面是一种类型， 进行强转 
	return typename add_rvalue_referenc<T>::type(a);
}

void f(int &x) {
	cout << "左值" << endl;
	return ;
}

void f(int &&x) {
	x = 9973;
	cout << " 右值" << endl;
	return ; 
}

} // end of haizei

int main() {
    int inta = 123, intb = 456;
   	int first = 10;
    cout << haizei::add2(inta, intb) << endl;
    cout << haizei::add2(123, 456) << endl;
    haizei::func2(haizei::test_param_func);
    A a(1000);
    B b(645);
    cout << a + b << endl;
    cout << haizei::add(2, 3) << endl;
    cout << haizei::add(2.3, 4.3) << endl;
    cout << haizei::add(2.3, 5) << endl;
    cout << haizei::add(5, 2.3) << endl;
    cout << haizei::add(string("hello"), "hello world") << endl;
    cout << haizei::add(a, b) << endl;
    cout << haizei::max(4, 3) << endl;
    cout << haizei::max(4.3, 3) << endl;
    cout << haizei::min(4, 3) << endl;
    cout << haizei::min(4.3, 3) << endl;
    haizei::PrintAny print;
    print(123);
    print(45678);
    print(3.4);
    print("hello world");
    print("hello haizei");
    print(&a);
    haizei::FoolPrintAny<string> f;
    f("hello world");
    haizei::FoolPrintAny<int> f2;
    f2(123);
    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl;
    cout << haizei::add(p, q) << endl;
    haizei::printAny(123, 34.5, "hello world", &a);
    haizei::Test<int(int, int)> f3;
    cout << f3(3, 4) << endl;

    haizei::Test<int(int, int, int, int)> f4;
    cout << f4(1, 2, 3, 4) << endl;

    haizei::Test<int(int, int, int, int, int)> f5;
    cout << f5(1, 2, 3, 4, 5) << endl;
    
    //move 
    haizei::f(n);
    haizei::f(haizei::move(n));
    cout << n << endl;
    return 0;
}
~~~

#### 2.5.3 functions的使用

~~~ c
#include<iostream>
#include<functional> 
using namespace std;

void f(function<int(int, int)> g){
	cout << g (3, 4) << endl;
	return ;	
}

int add(int a, int b) {
	return a + b;
}

struct MaxClass {
	int operator() (int a, int b) {
		return a > b ? a : b;
	}
};
//任何可以向函数一样被调用的都可以function都可以进行调用 
int main() {
	MaxClass max;
	//可以接受普通函数作为参数 
	f(add);
	f(max);
	return 0;
}
~~~





#### 2.5.4function实现

~~~ c
#include<iostream>
#include<functional> 
using namespace std;

//实现function模板类
namespace haizei {
	
template<typename RT, typename ...PARAMS> 
class base {
public :
    virtual RT operator()(PARAMS...) = 0;
    virtual ~base() {}
};

template<typename RT, typename ...PARAMS> 
class normal_func : public base<RT, PARAMS...> {
public :
    typedef RT (*func_type)(PARAMS...);
    normal_func(func_type func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }

private:
    func_type ptr;
};


template<typename C, typename RT, typename ...PARAMS> 
class functor : public base<RT, PARAMS...> {
public :
    functor(C &func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }

private:
    C &ptr;
};

template<typename RT, typename ...PARAMS> class function;
//他是正常的偏特化的模板 
template<typename RT, typename ...PARAMS>
class function<RT(PARAMS...)> {
	//传入只指针的够造函数  普通 
public :
    function(RT (*func)(PARAMS...)) 
    : ptr(new normal_func<RT, PARAMS...>(func)) {}
	
	
	//特殊的 
	
	template<typename T>
    function(T &&a) 
    : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(a)){}

    RT operator()(PARAMS... args) {
        return this->ptr->operator()(args...);
    }
    ~function() {
        delete ptr;
    }
    
private:
    base<RT, PARAMS...> *ptr;
};

}

void f(function<int(int, int)> g){
	cout << g (3, 4) << endl;
	return ;	
}

int add(int a, int b) {
	return a + b;
}

struct MaxClass {
	int operator() (int a, int b) {
		return a > b ? a : b;
	}
};
//任何可以向函数一样被调用的都可以function都可以进行调用 
//他无论是那种方式只要是进行赋值就调用构造函数 
int main() {
	MaxClass max;
	//可以接受普通函数作为参数 
	f(add);
	f(max);
	haizei::function<int(int, int)> g1(add);
	haizei::function<int(int, int)> g2(max);
	cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;
	return 0;
}
~~~

### 2.6模板的额拓展知识

#### 1.统计函数执行次数

* function 实现
  * 外部有一个函数， 对这个函数包装， 是他对外变相也和函数一项
  * 将类绑定在function上，对象里面有一个count 
  * 重载()
  * 然后我们进行count++
* 代码以及模板优化

~~~ c++
 ************************************************************************/
#include<iostream>
#include <functional>
using namespace std;


template<typename T, typename ...ARGS> class FunctionCnt;
template<typename T, typename ...ARGS>
class FunctionCnt<T(ARGS...)> {
public:
    //在这里使用自己的构造的haizei::function会发生端错误
    //是因为， 我们无论怎么样都回用系统的function,
    //在使用到g(g)的时候传诵的是一个参数， 它会在系统的function转换到自己的function中发生拷贝， 而我们自己的function没有拷贝函数， 所以发生了浅拷贝， 导致我们无法站到函数的传参， 重而发生了段错误，
    FunctionCnt(function<T(ARGS...)> g) : g(g), cnt(0) {}
    T operator()(ARGS... args) {
        cnt += 1;
        return g(args...);
    }
    int get() { return cnt; }
private:
    //如果在这里和上面同时使用自己的function的话， 根据机器的原因可能回发生段错误， 因为按照机器会产生返回值优化， 从而正常输出结果
    int cnt;
    function<T(ARGS...)> g;
};

int add(int a, int b) {
    return a + b;
}

//class FunctionCnt {
//public :
//    FunctionCnt(function<int(int, int)> g) : g(g), __cnt(0) {}
//    int operator()(int a, int b) {
//        __cnt += 1;
//        return g(a, b);
//    }
//    int cnt() { return __cnt; }
//
//private:
//    function<int(int, int)> g;
//    int __cnt;
//    
//};

int main() {
 // FunctionCnt add_cnt(add);
//    add_cnt(3, 4);
//    add_cnt(4, 5);
//    add_cnt(7, 9);
//    cout << add_cnt.cnt() << endl;
   FunctionCnt <int(int, int)> add_cnt(add);
    add_cnt(3, 4);
    add_cnt(4, 5);
    add_cnt(7, 9);
    cout << "add : " << add_cnt.get() << endl;
    return 0;
}

~~~

怎么解决上面注释的问题

~~~ c++

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
#include <functional>
using namespace std;

namespace haizei {

template<typename RT, typename ...PARAMS> 
class base {
public :
    virtual RT operator()(PARAMS...) = 0;
    //在基类中创建了一个虚函数进行去拷贝， 让他的子类去实现
    virtual base<RT, PARAMS...> *getCopy() = 0;
    virtual ~base() {}
};

template<typename RT, typename ...PARAMS> 
class normal_func : public base<RT, PARAMS...> {
public :
    typedef RT (*func_type)(PARAMS...);
    normal_func(func_type func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }
    virtual base<RT, PARAMS...> *getCopy() override {
        return new normal_func<RT, PARAMS...>(ptr);
    }

private:
    func_type ptr;
};

template<typename C, typename RT, typename ...PARAMS> 
class functor : public base<RT, PARAMS...> {
public :
    functor(C &func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }
    //进行去解决实现拷贝
    virtual base<RT, PARAMS...> *getCopy() override {
        return new functor<C, RT, PARAMS...>(ptr);
    }

private:
    C &ptr;
};

template<typename RT, typename ...PARAMS> class function;
template<typename RT, typename ...PARAMS>
class function<RT(PARAMS...)> {
public :
    function(RT (*func)(PARAMS...)) 
    : ptr(new normal_func<RT, PARAMS...>(func)) {}

    template<typename T>
    function(T a) 
    : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(a)){}
    
    function(const function &f) {
        this->ptr = f.ptr->getCopy();
    }
    function(function &&f) {
        this->ptr = f.ptr;
        f.ptr = nullptr;
    }
    
    RT operator()(PARAMS... args) {
        return this->ptr->operator()(args...);
    }
    ~function() {
        if (ptr != nullptr) delete ptr;
    }

private:
    base<RT, PARAMS...> *ptr;
};

} // end of haizei

void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
    return ;
}

int add(int a, int b) {
    return a + b;
}

int add2(int a, int b, int c) {
    return a + b + c;
}

struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b;
    }
};

template<typename T, typename ...ARGS> class FunctionCnt;
template<typename T, typename ...ARGS>
class FunctionCnt<T(ARGS...)> {
public :
    FunctionCnt(haizei::function<T(ARGS...)> g) : g(g), __cnt(0) {}
    int operator()(ARGS... args) {
        __cnt += 1;
        return g(args...);
    }
    int cnt() { return __cnt; }

private:
    haizei::function<T(ARGS...)> g;
    int __cnt;
};

int main() {
    function<int(int, int)> test_p;
    MaxClass max;
    test_p = add;
    cout << test_p(4, 10) << endl;
    test_p = max;
    cout << test_p(5, 10) << endl;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;
    
    FunctionCnt<int(int, int)> add_cnt(add);
    add_cnt(3, 4);
    add_cnt(4, 5);
    add_cnt(7, 9);
    cout << add_cnt.cnt() << endl;
    FunctionCnt<int(int, int, int)> add_cnt2(add2);
    add_cnt2(1, 2, 3);
    add_cnt2(4, 5, 6);
    cout << add_cnt2.cnt() << endl;
    return 0
~~~

2bind函数

~~~ c++

#include<iostream>
#include<functional>
using namespace std;

int add(int a, int b) {
    cout << a << " +" << b << " =" << a + b << endl;
    return a + b;
}

int add2(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
}

int add_cnt(function<int(int, int)> func, int &n, int a, int b) {
    n += 1;
    return func(a, b);
}

int main() {
    //placeholders代表的是参数列表的参数顺序
    function<int(int)> f = bind(add, 5, placeholders::_1);
    f(3), f(4), f(5);
    //function<int(int, int)> f2 = bind(add, 5, placeholders::_2, placeholders::_1);
    //f2(3, 4), f2(5, 6), f2(7, 8);
    function<int(int, int)> f3 = bind(add2, placeholders::_2, 6, placeholders::_1);
    f3(9, 10);
    function<int(int, int, int)> f4 = bind(add2, placeholders::_1, placeholders::_3, placeholders::_2);
    f4(1, 2, 3);

    //统计函数次数
    int n = 0;
    //function<int(int, int)> f5 = bind(add_cnt, add, n, placeholders::_1, placeholders::_2);
    //V这样n就是引用
    function<int(int, int)> f5 = bind(add_cnt, add, ref(n), placeholders::_1, placeholders::_2);
    f5(99, 88);
    f5(92, 80);
    f5(95, 78);
//按理来说应该是3， 但是输出0
    cout << n << endl;
    return 0;
}

~~~



2.c++线程类thread介绍

~~~ c++
#include<iostream>
#include<thread>
using namespace std;

void func() {
    cout << " hello world" << endl;
}

void func2(int x) {
    cout << x << "hello world" << endl;
}

void func3(int &x) {
    x += 1;
    cout << x << "hello world" << endl;
}

int main() {
    thread t1(func);
    //等待子线程结束
    t1.join();
    thread t2(func2, 2);
    t2.join();
    int n;
    thread t3(func3, ref(n));
    t3.join();
  //有点问题
    cout << n << endl;
    return 0;
}
g++ -std=c++11 23.thread.cpp -lpthread
~~~

#### 2.模板的图灵完备性

* 实现素数筛

~~~ c++

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

template<int n>
struct IsEven {
    static constexpr int r = !(n % 2);
};

template<int a, int b>
struct Add {
    static constexpr int r = a + b;
};

template<int n>
struct Sum {
    static constexpr int r = n + Sum<n - 1>::r;
};
template<>
struct Sum<0> {
    static constexpr int r = 0;
};

template<int n>
struct Factorial {
    static constexpr int r = n * Factorial<n - 1>::r;
};
template<>
struct Factorial<0> {
    static constexpr int r = 1;
};

template<int n, int i>
struct getNextN {
    static constexpr int r = (i * i > n ? 0 : n);
};

template<int n, int i>
struct getNextI {
    static constexpr int r = (n % i == 0 ? 0 : i + 1);
};

template<int n, int i>
struct IsTest {
    static constexpr int r = IsTest<getNextN<n, i>::r, getNextI<n, i>::r>::r;
};

template<int i>
struct IsTest<0, i> {
    static constexpr int r = 1;
};

template<int n>
struct IsTest<n, 0> {
    static constexpr int r = 0;
};

template<int n>
struct IsPrime {
    static constexpr int r = IsTest<n, 2>::r;
};

int main() {
    cout << IsEven<123>::r << endl;
    cout << IsEven<124>::r << endl;
    cout << Add<97, 87>::r << endl;
    cout << Sum<10>::r << endl;
    cout << Sum<100>::r << endl;
    cout << Factorial<5>::r << endl;
    cout << Factorial<10>::r << endl;
    
    cout << IsPrime<9973>::r << endl;
    cout << IsPrime<87>::r << endl;
    cout << IsPrime<1537>::r << endl;
    cout << IsPrime<65>::r << endl;
    return 0;
}
~~~





# 项目

## 1.首先实现一个设计一个打包函数参数的类

* ~~~ c++

  #include<iostream>
  #include<functional>
  using namespace std;

  class Task {
  public :
      template<typename T, typename ...ARGS>
      Task(T func, ARGS... args) {
          this->func = std::bind(func, args...);
      }
      void operator()() {
          this->func();
          return ;
      }
  private:
      function<void()> func;
  };

  void thread_func1(int a, int b) {
      cout << a << " + " << b << " = " << a + b << endl;
      return ;
  }

  int main() {
      Task t(thread_func1, 3, 4);
      t();
      return 0;
  }

  ~~~

* 由一个小bug, 我们在进行数之传输的时候希望我们串入的数值是什么就是什么

* ~~~ 
  this->func = std::bind(func, forward<ARGS>(args)...);
  ~~~

* c初步实现时这样的

* ~~~ c++

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
  #include <thread>
  using namespace std;

  class Task {
  public:
      template<typename T, typename ...ARGS>
      Task(T func, ARGS... args) {
          this->func = std::bind(func, forward<ARGS>(args)...);
      }
      void operator()() {
          this->func();
          return ;
      }

  private:
      function<void()> func;
  };

  class ThreadPool {
  public :
      ThreadPool(int n = 5) 
      : is_running(false), max_threads_num(n) {}
      void start() {
          if (is_running) return ;
          is_running = true;
          for (int i = 0; i < this->max_threads_num; i++) {
              threads.push_back(new thread(&ThreadPool::worker, this));
          }
          return ;
      }
      void worker() {
          cout << "worker : hello, I'm worker" << endl;
      }
      void stop() {
          if (is_running == false) return ;
          is_running = false;
          for (int i = 0; i < this->max_threads_num; i++) {
              threads[i]->join();
              delete threads[i];
          }
          threads.clear();
          return ;
      }

  private:
      bool is_running;
      int max_threads_num;
      vector<thread *> threads;
  };

  void thread_func1(int a, int b) {
      cout << a << " + " << b << " = " << a + b << endl;
      return ;
  }

  void thread_func2(int &n) {
      n += 1;
      return ;
  }

  int main() {
      Task t1(thread_func1, 3, 4);
      Task t2(thread_func1, 5, 6);
      Task t3(thread_func1, 7, 8);
      t1(), t2(), t3();
      int n = 0;
      
      Task t4(thread_func2, ref(n));
      t4(), t4(), t4();
      cout << n << endl;

      ThreadPool tp(6);
      tp.start();
      tp.stop();
      return 0;
  }

  ~~~

* ​

  ​