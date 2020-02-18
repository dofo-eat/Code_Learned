/*************************************************************************
	> File Name: OJ310.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月28日 星期六 14时06分42秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 1000000

int prime[N + 5] = {0};
int sum[N + 5] = {0};

/*long long int init(long long int n) {
    for(int i = 2; i <= n; i++) {
        int sum = 0;
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > N) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) sum++;
        }
        cout << prime[i] << " "<< sum << endl;
    }
}*/

int main () {
    int n;
    long long int sum = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        sum *= i;
    }
    init(sum);
    return 0;
}
