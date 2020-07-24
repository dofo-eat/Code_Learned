/*************************************************************************
	> File Name: 19.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月24日 星期五 09时41分52秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 300000
int arr[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    head = tail = 0;
    for (int i = 0; i < n; i++) {
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (i - q[head] >= k) head++;
        if (i + 1 >= k) {
            i + 1 == k || cout << " ";
            cout << arr[q[head]];
        }
    }
    cout << endl;
    head = tail = 0;
    for (int i = 0; i < n; i++) {
        while (tail - head && arr[q[tail - 1]] <= arr[i]) tail--;
        q[tail++] = i;
        if (i - q[head] >= k) head++;
        if (i + 1 >= k) {
            i + 1 == k || cout << " ";
            cout << arr[q[head]];
        }
    }
    cout << endl;
    return 0;
}
