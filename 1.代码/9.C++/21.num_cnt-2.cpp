/*************************************************************************
	> File Name: 21.num_cnt.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 08时10分12秒
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
