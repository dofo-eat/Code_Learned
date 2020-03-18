/*************************************************************************
	> File Name: OJ534.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月18日 星期三 20时29分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[25], check[1005] = {1};
int ans;

void func(int s, int sum) {//sum 表示到这位可所选的数加在一起的和是多少
    if(check[sum] == 0) {
        ans++;
        check[sum] = 1;
    }
    for(int i = s; i < n; i++) {
        sum += num[i];
        func(i + 1, sum);
        sum -= num[i];
    }
}

int main () {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    func(0,0);
    cout << ans << endl;
    return 0;
}
//类似与235
