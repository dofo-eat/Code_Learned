/*************************************************************************
	> File Name: OJ169.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月15日 星期五 18时16分20秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    getchar();
    char x;
    int a[27] = {0};
    string str;
    for(int i = 0; i < n; i++) {
        cin >> x;
      //  getchar();
        cin >> m;
        a[x - 65] = m;
    }
    //getchar();
    cin >> str;
    int sum = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z'){
            sum += a[str[i] - 65];
        }
    }
    cout << sum << endl;
    return 0;
}

