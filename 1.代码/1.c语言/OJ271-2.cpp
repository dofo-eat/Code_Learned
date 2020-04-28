/*************************************************************************
	> File Name: OJ271.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月28日 星期二 19时53分51秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 300000

int a[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;//队列中存储的是下标

int main () {
    int n, k;
    cin >> n>> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    //最小值的输出
    for(int i = 1; i < k; i++) {
        while(tail - head && a[q[tail - 1]] >= a[i]) tail--;//不符合就踢出队列
        q[tail++] = i;//进行比较来判断是否符合之后进入队列
    }
    for(int i = k; i <= n; i++) {
        while(tail - head && a[q[tail - 1]] >= a[i]) tail--;
        q[tail++] = i;
        if(q[head] <= i - k) head++;
        //正常头部出
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    head = tail = 0;
    for(int i = 1; i < k; i++) {
        while(tail - head && a[q[tail - 1]] <= a[i]) tail--;
        q[tail++] = i;
    }
    for(int i = k; i <= n; i++) {
        while(tail - head && a[q[tail - 1]] <= a[i]) tail--;
        q[tail++] = i;
        if(q[head] <= i - k) head++;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    return 0;
}
