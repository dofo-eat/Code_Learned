/*************************************************************************
	> File Name: new_merge_sort.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月23日 星期六 19时56分52秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
//重新设计归并排序
int merger_sort(int *num, int n){
    if(n <= 1) return 0;
    int ans = 0, mid = n/ 2;
    ans += merger_sort(num, mid);
    ans += merger_sort(num +mid, n - mid);
    int *temp = (int *) malloc (sizeof(int ) * n);
    int p1 = 0, p2 = mid, k = 0;
    while(p1 < mid || p2 < n) {
        if(p2 == n || p1 < mid && num[p1] <= num[p2]) {
            temp[k++] = num[p1++];
        } else {
            ans += mid - p1;
            temp[k++] = num[p2++];
        }
    }
    for(int i = 0; i < k; i++) {
        num[i] = temp[i];
    }
    return ans;
}

int main () {
    int n,a[100];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << merger_sort(a, n) << endl;
}
