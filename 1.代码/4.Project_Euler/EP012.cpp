/*************************************************************************
	> File Name: EP012.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月26日 星期四 19时49分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 1000000

int prinme[N + 5]= {0};
int f[N + 5] = {0};
int cnt[N + 5] = {0};//最小素因子幂次i的

void init() {
    for(int i = 2; i <= N; i++) {
        if(!prinme[i]) { 
            prinme[++prinme[0]]= i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for(int j = 1; j <= prinme[0]; j++) {
            if(prinme[j] * i > N) break;
            prinme[i * prinme[j]] = 1;
            if(i % prinme[j] == 0) {
                /*int a = i, cnt = 0;
                while(a % prinme[j] == 0) a /= prinme[j], cnt++;
                f[i * prinme[j]] = f[i] /(cnt + 1) * (cnt + 2);//代表当前素因子幂次
                break;*/
                cnt[i * prinme[j]] = cnt[i] + 1;
                f[i * prinme[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                break;
            } else {
                f[prinme[j] * i] = f[prinme[j]] * f[i];
                cnt[prinme[j] * i] = 1;
            }
        }
    }
    return ;
}

int main () {
    init();
    long long int n = 0, fac = 0;
    while(fac <= 500) {
        n += 1;
        if(n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else{
            fac = f[n >> 1] * f[n + 1];
        }
    }
    cout << n * (n + 1)/ 2 << endl;
    return 0;
}

