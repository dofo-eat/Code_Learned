/*************************************************************************
	> File Name: OJ475.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月16日 星期四 16时15分26秒
 ************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

int ans_len = 0;

int check(char *temp, char *num1) {
    int l1 = strlen(temp) - 1;
    int l2 = strlen(num1);
    if (l1 > l2) {
        return 1;
    } else if (l1 < l2) {
        return 0;
    }
    for (int i = ans_len, j = 0; j < l2; i--, j++) {
        if (temp[i] == num1[j]) continue;
        return temp[i] > num1[j];
    }
    return 1;
}

int main() {
    char num1[1005] = {0}, num2[1005] = {0};
    cin >> num1 >> num2;
    char temp[1005] = {'0'};
    int ans[1005] = {0}, ind = 0;
    for (int i = 0; i < strlen(num2); i++) {
        for (int j = ans_len; j > 0; j--) {
            temp[j + 1] = temp[j];
        }
        ans_len++;
        temp[1] = num2[i];
        int cnt = 1;
        for (int j = ans_len; j >= 1; j--) {
            if (temp[j] != '0') {
                cnt = j;
                break;
            }
        }
        ans_len = cnt;
        while (check(temp, num1)) {
            for (int i = 1, j = strlen(num1) - 1; j >= 0; i++, j--) {
                temp[i] -= num1[j];
                temp[i] += '0';
            }
            for (int i = 1; i <= ans_len; i++) {
                if (temp[i] < '0') {
                    temp[i + 1]--;
                    temp[i] += 10;
                }
            }
            int cnt2 = 0;
            for (int i = 1; i <= ans_len; i++) {
                if (temp[i] != '0') {
                    cnt2 = i;
                }
            }
            ans_len = cnt2;
            for (int i = cnt2 + 1; i < 1005; i++) {
                if (temp[i] == 0) break;
                temp[i] = 0;
            }
            ans[ind]++;
        }
        ind++;
    }
    int flag = 0;
    for (int i = 0; i < ind; i++) {
        if (flag == 0 && ans[i] == 0) {
            continue;
        }
        flag = 1;
        cout << ans[i];
    }
    if (!flag) cout << 0;
    cout << endl;
    /*
    flag = 0;
    for (int i = ans_len; i > 0; i--) {
        cout << temp[i];
        flag = 1;
    }
    if (!flag) cout << 0;
    cout << endl;
    */
    return 0;
}
 

 
