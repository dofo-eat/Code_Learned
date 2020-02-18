/*************************************************************************
	> File Name: OJ220.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年01月01日 星期三 12时27分59秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct student {
    string name;
    int chinese;
    int math;
    int English;
    int science;
    int sum;
};

bool cmp1(struct student a, struct student b) {
    if(a.chinese == b.chinese) return a.name < b.name;
    return a.chinese > b.chinese;
}
bool cmp2(struct student a, struct student b) {
    if(a.math == b.math) return a.name < b.name;
    return a.math > b.math;
}
bool cmp3(struct student a, struct student b) {
    if(a.English == b.English) return a.name < b.name;
    return a.English > b.English;
}
bool cmp4(struct student a, struct student b) {
    if(a.science == b.science) return a.name < b.name;
    return a.science > b.science;
}
bool cmp5(struct student a, struct student b) {
    if(a.sum == b.chinese) return a.name < b.name;
    return a.sum > b.sum;
}

int main () {
    int n;
    string name;
    int chinese, math, English, science;
    cin >> n;
    struct student a[101];
    for(int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].chinese >> a[i].math >> a[i].English >> a[i].science;
        a[i].sum = a[i].chinese + a[i].math + a[i].English + a[i].science;
    }
    sort(a, a + n, cmp1);
    for(int i = 0; i < 4; i++) {
        cout << a[i].name;
        i < 3 && cout << " ";
    }
    cout << endl;
    sort(a, a + n, cmp2);
    for(int i = 0; i < 4; i++) {
        cout << a[i].name;
        i < 3 && cout << " ";
    }
    cout << endl;
    sort(a, a + n, cmp3);
    for(int i = 0; i < 4; i++) {
        cout << a[i].name;
        i < 3 && cout << " ";
    }
    cout << endl;
    sort(a, a + n, cmp4);
    for(int i = 0; i < 4; i++) {
        cout << a[i].name;
        i < 3 && cout << " ";
    }
    cout << endl;
    sort(a, a + n, cmp5);
    for(int i = 0; i < 4; i++) {
        cout << a[i].name;
        i < 3 && cout << " ";
    }
    cout << endl;
    return 0;
}
