# C++

理解程序的运行流程

![图片](https://static.dingtalk.com/media/lALPGo_k8XshscHNBHLNB1I_1874_1138.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%228145301367%22%2C%22msgId%22%3A%224676817925879%22%7D&bizType=im&open_id=366609415)]()

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
  |           | 出对     |
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

