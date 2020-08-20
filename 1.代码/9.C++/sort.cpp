/*************************************************************************
	> File Name: sort.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月17日 星期一 14时33分19秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;

//返回的是课调用对象， 因为范围更广
bool cmp(int a, int b) {
    return a > b;
}

struct CMP {
    bool operator()(int a, int b) {
        return a > b;
    }
};

namespace haizei {
    template<typename T>
    struct greater {
        bool operator ()(const T &a, const T &b) {
            return a > b;
        }
    };

    template<typename T> 
    struct less {
        bool operator ()(const T &a, const T &b) {
            return a < b;
        }
    };
}

int main() {
    srand(time(0));
    int arr[10];
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    sort(arr, arr + 10, haizei::greater<int>());
    /*
    sort(arr, arr + 10, greater<int> ());
    sort(arr, arr + 10, less<int> ());
    */
    //加上个括号才是对象
    //sort(arr, arr + 10, CMP());
    //sort(arr, arr + 10, cmp);
    for(int i = 0; i < 10; i++) 
    cout << arr[i] << " ";
    return 0;
}
