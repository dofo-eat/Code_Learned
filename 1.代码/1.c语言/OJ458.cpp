/*************************************************************************
	> File Name: OJ458.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月18日 星期三 18时10分11秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct student{
    string name;
    string sex;
    int year;
    int month;
};
bool cmp(struct student a, struct student b) {
    if(a.year == b.year) {
        return a.month > b.month;
    }
    return a.year > b.year;
}
int main () {
    int n;
    string name, sex;
    int year, month;
    cin >> n;
    struct student a[101];
    for(int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].sex >> a[i].year >> a[i].month;
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++) {
        cout << a[i].name << " " << a[i].sex << " " << a[i].year << " " << a[i].month << endl;
    }
    return 0;
}
