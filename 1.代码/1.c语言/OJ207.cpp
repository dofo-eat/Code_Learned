/*************************************************************************
	> File Name: OJ207.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月11日 星期三 20时54分57秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct student {
    string name;
    int grade;
};

bool cmp(struct student a, struct student b) {
    return a.grade > b.grade;
}

int main() {
    int n, m, max = -1, min = 1000;
    string name;
    struct student a[35];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name;
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> m;
            sum += m;
            m > max && (max = m);
            m < min && (min = m);     
        }
        cout << sum << endl;
        struct student temp = {name, sum};
        a[i] = temp;    
    }
    sort(a, a + n, cmp);
    cout << a[0].name << endl;
    cout << max << " " << min << endl;
    return 0;
}
