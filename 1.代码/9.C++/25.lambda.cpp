/*************************************************************************
	> File Name: 25.lambda.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月17日 星期一 09时57分40秒
 ************************************************************************/

#include<iostream>
#include<typeinfo>
#include<functional>
using namespace std;

int main() {
    int n = 10000, m, x, y;
    //以方括号作为开头
    //它由两种返回形式
    //  它第一种就是通过编译器自动推导的
    //a捕获的n值为10000之后无论怎么计算都是10000
    //auto a =[n](int a, int b) {
      //  return a + b + n;
     //};
    
    //引用捕获
    auto a =[n](int a, int b) {
        return a + b + n;
     };
//这种是返回值后置
    /*auto a =[](int a, int b) -> double {
        double c = 12.3;
        if(rand() % 2) {
            return c;
        } else {
            return a + b;
        }
     }; *///为什么要加分号， 因为方括号后面的相当于一个值， 所以是一个赋值语句， 需要加上分号
    n = 1000000;
    auto b = [n](int a, int b) {
        return a +b + n;
    };
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << a(1, 2) << endl;
    cout << b(1, 2) << endl;
    return 0;
}
