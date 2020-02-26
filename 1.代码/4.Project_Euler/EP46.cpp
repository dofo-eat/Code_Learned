/*************************************************************************
	> File Name: EP46.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月29日 星期日 16时38分58秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
void init() {
    for (int i = 2; i <= max_n; i++) {
        if(!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;        
        }   
    }
    return ;
}

int is_sqrt(int n) {
    return 2 * n * n;
}
bool binary_search(int (*func)(int), int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return true;
    if (func(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(func, l, r, x);
}

int main() {
    init();
    int ans = 0;
    for (int i = 9; i <= max_n; i += 2) {
        if (!is_prime[i]) continue;
        int flag = 0;
        for (int j = 1; j <= prime[0] && prime[j] < i; j++) {
            if (binary_search(is_sqrt, 1, i - prime[j], i - prime[j])) {
                flag = 1;
                break;                            
            }       

        }
        if (flag) continue;
        ans = i;
        break;            
    }
    cout << ans << endl;
    return 0;
}
