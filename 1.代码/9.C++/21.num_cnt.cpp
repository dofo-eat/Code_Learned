/*************************************************************************
	> File Name: 21.num_cnt.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 08时10分12秒
 ************************************************************************/
#include<iostream>
#include <functional>
using namespace std;

int cnt = 0;

template<typename A, typename B,typename OP>
int do_op(A a, B b, OP op) {
    cnt++;
    return op(a, b);
}

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
//  FunctionCnt add_cnt(add);
//    add_cnt(3, 4);
//    add_cnt(4, 5);
//    add_cnt(7, 9);
//    cout << add_cnt.cnt() << endl;
    cout << do_op(1, 2, add) << endl;
    cout << do_op(2, 3, add) << endl;
    cout << do_op(3, 4, add) << endl;
    cout << cnt << endl;
    return 0;
}
