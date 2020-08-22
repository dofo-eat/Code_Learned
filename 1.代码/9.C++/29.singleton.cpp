/*************************************************************************
	> File Name: 29.singleton.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月22日 星期六 16时08分48秒
 ************************************************************************/

#include<iostream>
#include<mutex>
using namespace std;

class Singleton {
public :
    //获得单例模式唯一类的地址
    static Singleton *getInstance() {
        //解决懒汉模式的来一个九进行加锁的问题, 实现双宏判断, 即保证的线程的安全, 执行效率页式安全的
        if(single == nullptr) {
            std::unique_lock<mutex> lock(m_mutex);
            if(single == nullptr) {
                single = new Singleton();
            }
        }
        return single;
    }

private:
    //将类放在私有的位置上, 外部访问不到
    static Singleton *single;
    static std::mutex m_mutex;
    Singleton() = default;
    Singleton(const Singleton &) = default;
    ~Singleton() {}
};

//类外初始化为空地址, 静态的一种初始化方法
Singleton *Singleton::single = nullptr;
std::mutex Singleton::m_mutex;
int main() {
    Singleton *p = Singleton::getInstance();
    /*地址被获得析构函数没有被私有化还是能被删除的
    Singleton *p = Singleton::getInstance();
    delete p;*/
    return 0;
}
