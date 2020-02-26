/*************************************************************************
	> File Name: EP29.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月29日 星期日 14时15分34秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define N 10000
#define M 210

int result[N + 5][M];
int result_len = 0;

int find_result(int *num) {
    for(int i = 0; i < result_len; i++) {
        if(memcmp(result + i, num, sizeof(int) * M) == 0) {
            return i + 1;
        }
    }
    return 0;
}

int main () {
    for(int a = 2; a <= 100; a++) {
        for(int b = 2; b <= 100; b++) {
            int temp[M] = {1, 1, 0};
            for(int i = 0; i < b; i++) {
                for(int j = 1; j <= temp[0]; j++) temp[j] *= a;
                for(int j = 1; j <= temp[0]; j++) {
                    if(temp[j] < 10) continue;
                    temp[j + 1] += temp[j] / 10;
                    temp[j] %= 10;
                    temp[0] += (temp[0] == j);
                }
            }
            if(find_result(temp) == 0) {
                memcpy(result + result_len, temp, sizeof(int) * M);
                result_len += 1;
            }
        }
    }
    cout << result_len << endl;
    return 0;
}
