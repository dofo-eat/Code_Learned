/*************************************************************************
	> File Name: 12.test.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月24日 星期日 19时56分22秒
 ************************************************************************/
#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for(int i = x; i <= y; i++) {
        if((i % 100 != 0 && i % 4 == 0) || i % 400 == 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
