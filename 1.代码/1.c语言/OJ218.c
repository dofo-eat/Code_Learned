/*************************************************************************
	> File Name: OJ218.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月08日 星期日 13时42分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define swap(a,b) {\
    __typeof(a) c = a; a = b;b = c;\
}

struct Node{
    int height, num;
};

bool cmp(struct Node a, struct Node b) {
    if(a.height == b.height) return a.num < b.num;
    return a.height < b.height;
}
int main() {
    int n, max = -1, min = 1000;
    string name;
    struct student a[35];
    cin >> n;
    for(int i = 0; i < 4; i++) {
        cin >> name;
        int sum = 0, n;
        for(int i = 0; i < 4; i++) {
            cin >> m;
            m > max && (max = m);
            m < min && (min = m);
            sum += m;
        }
        cout << sum << endl;
        struct student temp = {name, sum};
        a[i] = temp;
    }
    sort(a, a + n,cmp);
    cout << a[0].name << endl;
    cout << max << " " << min << endl;
    return 0;
}
