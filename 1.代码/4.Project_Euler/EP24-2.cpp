/*************************************************************************
	> File Name: EP24-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月28日 星期六 20时16分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<algorithm>

int main() {
    int num[10];
    for(int i = 0; i < 10; i++) num[i] = i;
    int k = 999999;
    do{
        next_permutation(num, num + 10);
        k -= 1;
    } while(k);
    for(int i = 0; i < 10; i++) {
        cout << num[i];
    }
    cout << endl;
    return 0;
}
