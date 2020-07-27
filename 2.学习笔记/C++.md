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

## 3.构造函数和析构函数

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

* 只有转换函数没有作用在对向定义阶段

* 为什么要加？ V

  ```c
  //People() = default;
  为了把隐藏的规则显示出来

  把所有的逻辑显示在代码中
  //People() = delete;
  意思是不支持默认构造函数
  为了方便代码维护


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
    先调用赋值运算符 声称一个匿名对象， c的引用就绑定在匿名对象上了， 之后按照（转换函数）正常逻辑调用， 最后在释放你匿名对象
    ~~~

  * ​

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

~~~



