/*************************************************************************
	> File Name: 4.迷路的牛牛.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月19日 星期三 16时24分17秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

char a[4] = {'w', 'N', 'E', 'S'};


int main(){
    int n; cin >> n;
    int ans = 0;
    char dir[] = "NESW";
    string str; cin >> str;
    for(int i = 0; i < n; i++)
        ans = (ans + (str[i] == 'L' ? -1:1) + 4) % 4;
    cout << dir[ans%4] << endl;
    return 0;
}

/*int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            ans--;
        } else {
            ans++;
        }
        if(ans == -1) {
            ans = 3;
        } 
        if(ans == 4) {
            ans = 0;
        }
    }
    if(ans == 0) {
        cout << "N" << endl;
    } else if(ans == 1) {
        cout << "E" << endl;
    } else if(ans == 2) {
        cout << "S" << endl;
    } else {
        cout << "W" << endl;
    }
    return 0;
}*/
