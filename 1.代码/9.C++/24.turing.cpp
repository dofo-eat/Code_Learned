/*************************************************************************
	> File Name: 24.turing.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 15时54分58秒
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
struct IsTest<2, i> {
    static constexpr int r = 1;
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

template<int n>
struct SumPrime {
    static constexpr int r = (n * IsPrime<n>::r) + SumPrime<n - 1>::r;
};

template<>
struct SumPrime<1> {
    static constexpr int r = 0;
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

    cout << SumPrime<10>::r << endl;
    cout << SumPrime<40>::r << endl;
    return 0;
}

