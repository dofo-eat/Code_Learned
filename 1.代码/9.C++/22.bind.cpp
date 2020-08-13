/*************************************************************************
	> File Name: 22.bind.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 11时18分00秒
 ************************************************************************/

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
