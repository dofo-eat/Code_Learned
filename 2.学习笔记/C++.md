# C++

理解程序的运行流程

![图片](https://static.dingtalk.com/media/lALPGo_k8XshscHNBHLNB1I_1874_1138.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%228145301367%22%2C%22msgId%22%3A%224676817925879%22%7D&bizType=im&open_id=366609415)]()

* 以及c++是把运行时候的bug改为程序编译时候的bug
* 对于问题在编译成功的时候面对外界更改的因素， 按照严格的规范来， 对于设定的类型只要不合理的public等类的更改， 会报漏出来

## 一.从C到C++

### 1.包含

* c语言的29个头文件
* 头文件现在58
* 异常处理
* 类和对象
* STL
* 模板
* Lambda

## 2.编程範式

* 面向过程
* 面向对象
* 泛型编程
  * 去掉了类型的限定
* 函数事编程
* 提高编程效率
  * 代码开发
  * 测试
  * 维护

## 3.queue

### 1.queue类：对列

* 头文件

* 命名空间std

* 声明 queue<data_type> q;

* | q.front() | 查看对首   |
  | --------- | ------ |
  | q.empty() | 对列判空   |
  | q.push()  | 入对     |
  | q.pop()   | 出对     |
  | q.size()  | 对列元素数量 |

## 4.Stack



## 5.string

### 1,string 类：字符串

* 头文件 string

* 命名空间：std

* string s1, s2;

* | s1 == s2    | 字符串判等     |
  | ----------- | --------- |
  | s1 < s2     | 字典序小于     |
  | s1 > s2     | 字典序大于     |
  | s1 += s2    | 字符串连接     |
  | s1.length() | 字符串长度O（1） |

## 6.HASH——MAP类说明

### 1.hash_map类：还系表

* 头文件<hash_map> / <ext/hash_map>

* 命名空 _gnu_cxx

* 声明 hash_map<key_type, value_tye, hash_func> h;

* | h.find(key) | 判断某个key值是否在hash_map中 |
  | ----------- | -------------------- |
  |             | 将value存储在key位上       |
  |             | 访问key值对应value        |
  | h,begin()   | 起始位置                 |
  | h.end()     | 结束位置                 |

* 数组合函数的转换是时间换空间， 空间换时间

* 底层实现红黑树

## 7.unordered_map类说明

### 1.unordered_map哈希表

* 头文件 unordered map
* 命名空间 std（底层实现hashmap）


## 8.set

* 示例

~~~ c
#include<iostream>
#include<set>
using namespace std;
//底层结构是红黑树
int main() {
    set<int> s;
    s.insert(234);
    s.insert(252);
    s.insert(563);
    s.insert(213);
    cout << s.size() << endl;
    s.insert(252);
    cout << s.size() << endl;
    cout << *(s.begin()) << endl;
    //遍历返回最小值
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
    s.erase(s.begin());
    cout << *s.begin() << endl;
    return 0;
}

~~~



~~~ c
287
#include<iostream>
#include<set>
using namespace std;

typedef pair<int, int> PII;

int main() {
    int n, a, t = 0;
    //t代表时间戳, 保证数据不会重复
    cin >> n;
    set<PII> s;
    for(int i = 0; i < n; i++) {
        cin >> a;
        s.insert(PII(a, t++));
    }
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        sum += a + b;
        s.insert(PII(a + b, t++));
    }
    cout << sum << endl;
    return 0;
}

~~~

* 256国王游戏

  * 题目描述
    ​ 恰逢 H 国国庆,国王邀请 n 位大臣来玩一个有奖游戏。首先,他让每个大臣在左、右手上面分别写下一个整数，国王自己也在左、右手上各写一个整数。然后，让这 n 位大臣排成一排，国王站在队伍的最前面。排好队后，所有的大臣都会获得国王奖赏的若干金币，每位大臣获得的金币数分别是：排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数,然后向下取整得到的结果。

    ​ 国王不希望某一个大臣获得特别多的奖赏，所以他想请你帮他重新安排一下队伍的顺序，使得获得奖赏最多的大臣，所获奖赏尽可能的少。注意，国王的位置始终在队伍的最前面。

    输入
    ​ 第一行包含一个整数 n，表示大臣的人数。

    ​ 第二行包含两个整数 a 和 b，之间用一个空格隔开,分别表示国王左手和右手上的整数。（均小于 10000）

    ​ 接下来 n 行，每行包含两个整数 a 和 b，之间用一个空格隔开，分别表示每个大臣左手和右手上的整数。（均小于 10000）

    输出
    ​ 输出一个整数，表示重新排列后的队伍中获奖赏最多的大臣所获得的金币数。

    ​


```c
nclude <iostream>
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

#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];

bool cmp(int i, int j) {
    return a[i] * b[i] < a[j] * b[j];
}

struct BigInt : vector<int> {
    BigInt() {}
    BigInt(int x) {
        push_back(x);
        proccess_digit();
    }
    BigInt(vector<int> &v) : vector<int>(v) { proccess_digit(); }
    
    BigInt operator/(int x) {
        int y = 0;
        vector<int> ret(size());
        for (int i = size() - 1; i >= 0; i--) {
            y = y * 10 + at(i);
            ret[i] = y / x;
            y %= x;
        }
        return ret;
    }
    void operator*=(int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        proccess_digit();
        return ;
    }
    bool operator>(const BigInt &a) {
        if (size() - a.size()) return size() > a.size();
        for (int i = size() - 1; i >= 0; i--) {
            if (at(i) - a[i]) return at(i) > a[i];
        }
        return false;
    }
    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while (size() > 1 && at(size() - 1) == 0) pop_back();
        return ;
    }
}; 

ostream &operator<<(ostream &out, const BigInt &v) {
    for (int i = v.size() - 1; i >= 0; --i) {
        out << v[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }
    sort(ind + 1, ind + n + 1, cmp);
    BigInt p = a[ind[0]], ans = 0;
    for (int i = 1; i <= n; i++) {
        BigInt temp = p / b[ind[i]];
        if (temp > ans) ans = temp;
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}
```
## 二.类和对象

### 1.类型和变量

* 类型等于类型数据+类型操作

| 类    | 对象   |
| ---- | ---- |
| 狗    | 黑子   |
| 人    | 肖战   |

### 2.属性和方法

~~~ c++
class People {
    string name;
    Day birthday;
    double height;
    double weight;
    void say(string word);
    void run(Location &loc);
}//偏向于声明
~~~

~~~ c++
#include<iostream>
#include<algorithm>
using namespace std;
//默认private
class People {
    friend int main();
    int x, y;
    //声明
public:
    void set(int x);
    void say();
};

//默认public
struct People2 {
    int x, y;
};

void People::set(int x) {
    cout << "set function:" << this << endl;
    this->x = x;
    return ;
}

void People::say() {
    cout << x << " " << y << endl;
    return;
}

int main() {
    People a;
    cout << "a function ；" << &a << endl;
    People2 b;
    a.y = 18432;
    a.set(3);
    b.x = 4;
    a.say();
    cout << b.x << endl;
    cout << a.y << endl;
    return 0;
}

~~~



### 3.访问权限

| public    | 公共访问权限         |
| --------- | -------------- |
| private   | 私有访问权限         |
| protected | 手保护的访问权相（）     |
| friendly  | 有元方法(一般所都是类外的) |

## 三.构造函数和析构函数

| 构造/析构函数                 | 使用方式 |
| ----------------------- | ---- |
| 默认构造函数                  |      |
| People(string name)     |      |
| People(const People &a） |      |
| ~peopel                 |      |

~~~ c++
 ************************************************************************/

#include<iostream>
using namespace std;

class People {
public:
  //通常都是自动调用的
    People() {
        cout << "default constructor" << endl;
    }
    ~People() {
        cout << "destructor" << endl;
    }
};

int main() {
    People a;
        cout << "hello world" << endl;
    return 0;
}
//默认构造函数
~~~

~~~ c++

//有参数构造

class People {
public:
    People() {}//为了不a报错添加的由参构造函数

    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    ~People() {
        cout << "destructor" << endl;
    }
    string name;
};

int main() {
    People b("hahahah");
    People a = string("hai");
    cout << a.name << endl;
    cout << "hello world" << endl;
}
//有参构造
//拥有一个参数的又可以叫转换类型参数  
超级特殊

int add(People a, People b) {
    return a.x + b.x;
}

int main() {
    cout << add(4, 5) << endl;
}//可以运算
在参数传递过程中进行自动的类型转换
~~~

~~~ c++
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

void incr(int &a) {
    a += 1;
    return ;
}

int main() {
    int n = 7;
    incr(n);
    cout << n << endl;
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
}
//引用inrc
~~~

~~~ c++
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

int main() {
    int n = 7;
    incr(n);
    cout << n << endl;
    People a = string("hai");
    People e = a;
    cout << e.name << endl;
    cout << e.x << endl;
}
//拷贝构造函数
为什么拷贝构造函数一定会传引用
因为会无限递归是展开
如下图
~~~

![图片](https://static.dingtalk.com/media/lALPDhJztliAp0fNAirNArk_697_554.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22366609415%3A366609415%22%2C%22msgId%22%3A%224712193640609%22%7D&bizType=im&open_id=366609415)



* 总结
* 只有转换函数没有作用在对向定义阶


## 4.类属性方法

### 4.1 访问权限

* 所有在类中实现的方法都叫作对象方法（都是跟着对象走的） 
* 成员方法
  * 它可以访问一个特殊的成员变量叫做this指针
  * 方便外部调用
* 成员属性
  * 成员属性
  * 方便内部调用
  * 表述某一个对象的具体内容

### 4.2 类属性与方法

* 类属性局为1 ，对象共享

* static定义

* 单反是调构造函数的总数加1， 析构函数-1；

  * 统计系统中对象的格式有一个潜在的小问题由一个特殊的转换构造函数的问题， 不存的话就没有问题

  * 这种机制只在定义的时候才会调用

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
    using namespace std;

    class Point {
    public :
        Point() {
            cout << "constructor : " << this << endl;
            Point::total_cnt += 1;
        }
        Point(const Point &a) : Point() {
            cout << "copy constructor : " << this << endl;
            this->x = a.x;
            this->y = a.y;
        }
        Point(double z) : Point() {
            cout << "convert constructor : " << this << endl;
            this->x = 99, this->y = 99;
        }
        Point(int x, int y) : Point() {
            cout << "param constructor : " << this << endl;
            this->x = x;
            this->y = y;
        }

        void operator=(const Point &a) {
            cout << "operator= : " << this << endl;
            this->x = a.x, this->y = a.y;
            return ;
        }
        static int T() { return Point::total_cnt; }

        ~Point() {
            cout << "destructor : " << this << endl;
            Point::total_cnt -= 1;
        }
        
    private:
        int x, y;
        static int total_cnt;
    };

    int Point::total_cnt = 0;

    void test() {
        Point a;
        cout << Point::T() << endl;
        return ;
    }

    int main() {
        Point a;
        cout << a.T() << endl;
        test();
        Point b;
        cout << b.T() << endl;
        Point c(3, 4);
        cout << c.T() << endl;
        Point d(3.4);
        cout << d.T() << endl;
        c = 5.6;
        cout << c.T() << endl;
        cout << &a << endl;
        cout << &b << endl;
        cout << &c << endl;
        cout << &d << endl;
        return 0;
    }
    //先出现的后析构

    c = 5.6逻辑
    先调用赋值运算符 声称一个匿名对象， c的引用就绑定在匿名对象上了， 之后按照（转换函数）正常逻辑调用， 最后在释放你匿名对象  ~~~
    ~~~

  *

  ![图片](https://static.dingtalk.com/media/lALPDg7mN7QPeU3NAafNAyA_800_423.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22366609415%3A366609415%22%2C%22msgId%22%3A%224723136161034%22%7D&bizType=im&open_id=366609415)

### 4.3const方法

* 不改变对象的属性值
* 作用是杯const类型嗯的对象进行调用 const只能调用const

### 5.总结

* //先出现的后析构
  * 因为后来构建的可能依赖于先构建 的
  * 否则的话可能会出现bug

### 6.对象和引用

* 都只作用存储空间

### 7.返回值优化

#### 7.1对象的初始化

SomeClass

* 开辟对象数据区
* 匹配构造函数
* 完成构造

#### 7.2返回值优化

![图片](https://static.dingtalk.com/media/lALPDh0cMke_KcjNASzNBCU_1061_300.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22366609415%3A366609415%22%2C%22msgId%22%3A%224722273252459%22%7D&bizType=im&open_id=366609415)

* 为什么要加？ V

  ```c
  //People() = default;
  为了把隐藏的规则显示出来

  把所有的逻辑显示在代码中
  //People() = delete;
  意思是不支持默认构造函数
  为了方便代码维护
  ```


  ```
## 4.类属性方法

### 4.1 访问权限

* 所有在类中实现的方法都叫作对象方法（都是跟着对象走的） 
* 成员方法
  * 它可以访问一个特殊的成员变量叫做this指针
  * 方便外部调用
* 成员属性
  * 成员属性
  * 方便内部调用
  * 表述某一个对象的具体内容

### 4.2 类属性与方法

* 类属性局为1 ，对象共享

* static定义

* 单反是调构造函数的总数加1， 析构函数-1；

  * 统计系统中对象的格式有一个潜在的小问题由一个特殊的转换构造函数的问题， 不存的话就没有问题

  * 这种机制只在定义的时候才会调用

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
    using namespace std;

    class Point {
    public :
        Point() {
            cout << "constructor : " << this << endl;
            Point::total_cnt += 1;
        }
        Point(const Point &a) : Point() {
            cout << "copy constructor : " << this << endl;
            this->x = a.x;
            this->y = a.y;
        }
        Point(double z) : Point() {
            cout << "convert constructor : " << this << endl;
            this->x = 99, this->y = 99;
        }
        Point(int x, int y) : Point() {
            cout << "param constructor : " << this << endl;
            this->x = x;
            this->y = y;
        }

        void operator=(const Point &a) {
            cout << "operator= : " << this << endl;
            this->x = a.x, this->y = a.y;
            return ;
        }
        static int T() { return Point::total_cnt; }

        ~Point() {
            cout << "destructor : " << this << endl;
            Point::total_cnt -= 1;
        }
        
    private:
        int x, y;
        static int total_cnt;
    };

    int Point::total_cnt = 0;

    void test() {
        Point a;
        cout << Point::T() << endl;
        return ;
    }

    int main() {
        Point a;
        cout << a.T() << endl;
        test();
        Point b;
        cout << b.T() << endl;
        Point c(3, 4);
        cout << c.T() << endl;
        Point d(3.4);
        cout << d.T() << endl;
        c = 5.6;
        cout << c.T() << endl;
        cout << &a << endl;
        cout << &b << endl;
        cout << &c << endl;
        cout << &d << endl;
        return 0;
    }
    //先出现的后析构

    c = 5.6逻辑
    先调用赋值运算符 声称一个匿名对象， c的引用就绑定在匿名对象上了， 之后按照（转换函数）正常逻辑调用， 最后在释放你匿名对象  ~~~

  *

  ![图片](https://static.dingtalk.com/media/lALPDg7mN7QPeU3NAafNAyA_800_423.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22366609415%3A366609415%22%2C%22msgId%22%3A%224723136161034%22%7D&bizType=im&open_id=366609415)

### 4.3const方法

* 不改变对象的属性值
* 作用是杯const类型嗯的对象进行调用 const只能调用const

### 5.总结

* //先出现的后析构
  * 因为后来构建的可能依赖于先构建 的
  * 否则的话可能会出现bug

### 6.对象和引用

* 都只作用存储空间

### 7.返回值优化

#### 7.1对象的初始化

SomeClass

* 开辟对象数据区
* 匹配构造函数
* 完成构造

#### 7.2返回值优化

![图片](https://static.dingtalk.com/media/lALPDh0cMke_KcjNASzNBCU_1061_300.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22366609415%3A366609415%22%2C%22msgId%22%3A%224722273252459%22%7D&bizType=im&open_id=366609415)

​~~~ c++
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

class People {
public :
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
    }

private:
    string name;
};

People func() {
    People temp_a("hug");
    return temp_a;
}

int main() {
    People a = func();
    return 0;
}

​~~~
g++ -fno-elide-constructor 
  ```

### 

### 8.深拷贝和浅拷贝





## 四、运算符重载

### 1，简单重载cin cout

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

namespace haizei {

class istream {
public :
    istream &operator>>(int &n) {
        std::cin >> n;
        return *this;
    }
private:

};

class ostream {
public :        
    ostream &operator<<(int &n) {
        std::cout << n;
        return *this;
    }
    ostream &operator<<(const char *msg) {
        std::cout << msg;
        return *this;
    }
private:

};
    
istream cin;
ostream cout;
};

int main() {
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n << " " << m << "\n";
    return 0;
}
~~~

部分重载示例

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

class Point {
public :
    Point() : __x(0), __y(0) {}
    Point(int x, int y) : __x(x), __y(y) {}
    int x() const { return __x; }
    int y() const { return __y; }
    
    Point operator+(const Point &a) {
        return Point(x() + a.x(), y() + a.y());
    }
    Point &operator+=(const Point &a) {
        __x += a.x();
        __y += a.y();
        return *this;
    }
    Point &operator++() {
        __x += 1;
        __y += 1;
        return *this;
    }
    Point operator++(int) {
        Point temp(*this);
        __x += 1;
        __y += 1;
        return temp;
    }

private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a) {
    out << "Point (" << a.x() << ", " << a.y() << ")";
    return out;
}

int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a + b << endl;
    cout << "pre incr : " << ++(c += b) << endl;
    cout << c << endl;
    cout << "after incr : " << c++ << endl;
    cout << c << endl;
    int n = 6, m = 7;
    (n += m)++;
    cout << n << endl;
    return 0;
}

~~~

~~~ c++
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

~~~

~~~ c++
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

class A {
public :
    int x, y;
};

class B {
public :
    B() : obj(nullptr) {
        arr = new int[10];
        arr[3] = 9973;
    }
    B(A *obj) : B() {
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
        return ;
    }
    A *operator->() {
        return obj;
    }
    A &operator*() {
        return *obj;
    }

    ~B() {
        delete arr;
    }
private:
    int *arr;
    A *obj;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "A(" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    B add;
    cout << add(3, 4) << endl;
    cout << add[3] << endl;
    add[3] = 8876;
    cout << add[3] << endl;
    add["hello world"];
    A a;
    a.x = 67, a.y = 99;
    B p = &a;
    cout << p->x << " " << p->y << endl;
    cout << *p << endl;
    return 0;
}

~~~

## 五 继承

* 封装：我该有的和我应该做的
* 继承：叫一声爸爸， 你将拥有财富
* 多态：我就是我不一样的烟火

### 1.继承权限是值子类从父类继承过来的权限

* 只能更低， 不能更高
* 影响的是外部访问子类继承自父类继承来的属性和方法访问的权限

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

class Animal {
public :
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << "my name is : " << __name << ", my age is : " << age << endl;
    }

protected:
    string __name;

private:
    int age;//是一个声明， 由一个对象就有一个age
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
//受保护的权限Bat
//不想让外部访问但是想让子类可以访问的权限
~~~

### 2.父类子类的构造函数

#### 2.1分为三部 

* 头部， 初始化列表 逻辑 (Cat() : 初始化列表 {(逻辑又成为方法（类内部的）)})、
  * 初始化列表包含父类的构造， 在包含子类的属性和方法、
  * 所以子类调用， 父类调用， 父类结束， 子类结束总而言之， 时父类的先完成构造， 子类在完成构造

~~~ c++
#include<iostream>
using namespace std;

class D {
public:
    D() {cout << "D constructor" << endl;}
};

class A {
public:
    //不像按默认顺序就加上这一行代码， 传参
    //A() = delete;
    A() {cout << "A constructor" << endl;}
};
class B {
public:
    B() {cout << "B constructor" << endl;}
};
class C :public D {
public:
    //显示的初始化列表
    //C(): b(), a() {cout << "C constructor" << endl;}
    //初始化顺序是按照定义的顺序来进行初始化的
    
    C(): a(), b() {cout << "C constructor" << endl;}

private:
    B b;
  	A a;//输出的顺序时D B A C
  //因为这里我们声明的顺序是B 在A的前面
};

int main () {
    C c;
    return 0;
}

~~~

~~~ c++
***************************************************************/

#include<iostream>
using namespace std;

class D {
public:
    D() {cout << "D constructor" << endl;}
    ~D() {cout << "D distructor " << endl;}
};

class A {
public:
    //不像按默认顺序就加上这一行代码， 传参
    //A() = delete;
    A() {cout << "A constructor" << endl;}
    ~A() {cout << "A constructor" << endl;}
};
class B {
public:
    B() {cout << "B constructor" << endl;}
    ~B() {cout << "B distructor" << endl;}
};
class C :public D {
public:
    //显示的初始化列表
    //C(): b(), a() {cout << "C constructor" << endl;}
    //初始化顺序是按照定义的顺序来进行初始化的
    
    C(): a(), b() {cout << "C constructor" << endl;}
    ~C() {cout << "c destructor " << endl;}

private:
    B b;
    A a;
};

int main () {
    C c;
    return 0;
}//析构对的顺序
~~~

### 3.菱形继承

![图片](https://static.dingtalk.com/media/lALPDhmOs7RU9XnNAXLNAkQ_580_370.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22366609415%3A366609415%22%2C%22msgId%22%3A%224740817106215%22%7D&bizType=im&open_id=366609415)

~~~ c++
//现象1指代不明
#include<iostream>
using namespace std;

struct A {
    int x;
};
struct B :public A {
    void set(int x) {
        //更改的是A的X值
        this->x = x;

    }
};
struct C :public A {
//读取x
    int get() {
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

~~~

* 解决输出结果冲突

~~~ c++
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
//会发现输出的D的存储空件会变得更大了
//所以不提倡多重继承
~~~

#### 1.虚继承的对象模型 

![img](https://static.dingtalk.com/media/lALPGo_k8dQ28jbNBiDNC1Y_2902_1568.png?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%228145301367%22%2C%22msgId%22%3A%224759153734451%22%7D&bizType=im&open_id=366609415)

### 4.拷贝赋值继承

~~~ c++
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

~~~

## # 5.实现自己的string

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

namespace haizei {
class string {
public :
    string() {
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) {
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
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
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }
    int size() { return this->__length; }

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
    cout << s1 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 << endl;
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }
    return 0;
}
~~~

## 六.多态

### 1.普通的成员方法跟着类走

~~~ c++
ass Cat : public Animal {
public:
    //加不加override之后只是把让一些错误在运行时候的bug暴洛在运行时器
    void run() override{
        //判断事不是真正的重载了run
        cout << "I can run with four legs" << endl;
    }
};

int main () {
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
}

~~~

* 主要说的是虚函数
* 编译时状态和运行时状态
  * 运行时状态需要存储调用节点
  * 高级功能都是有一定的代价

#### 2.虚函数精讲

* 我们普通函数加上一个虚函数， 

* 会产生一个虚函数表

  * 虚函数的每一个格子存储的是函数（方法）地址
  * 它所存取的函数总共大小都是固定的， 它不影响对象的大小
  * ![图片](https://static.dingtalk.com/media/lALPDgQ9u_e7F-7NAsnNAik_553_713.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22366609415%3A366609415%22%2C%22msgId%22%3A%224759473890229%22%7D&bizType=im&open_id=366609415)
  * 头部存储8个字节， 就是虚函数的表

  ~~~ c++

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

  int main () {
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

  ~~~

  ​

