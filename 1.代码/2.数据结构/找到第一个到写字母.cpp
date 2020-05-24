/*************************************************************************
	> File Name: 找到第一个到写字母.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月23日 星期六 17时18分35秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

int find_first_capital_letter(char *str, int len) {
    int l = 0, r = len -1, mid;
    while (l <  r) {
        mid = (l + r) / 2;
        if (str[mid] >= 'A' && str[mid] <= 'Z') {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}


int main() {
    char str[100000+5];
    scanf("%s", str);
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; i < 100000; ++i) {
        int x = find_first_capital_letter(str, len);
        sum += x;
    }
    printf("%d\n", find_first_capital_letter(str, len));
    return 0;
}
