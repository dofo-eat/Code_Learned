/*************************************************************************
	> File Name: OJ441.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月01日 星期日 14时11分05秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
        int x, n;
        scanf("%d %d", &x, &n);
        int w[7]= {0 ,2, 2, 2, 2, 2, 0};
        int sum = 0;
    for(int i = 0; i < n; i++) {
                sum += w[(x + i) % 7];    
            
    }
        printf("%d", sum);
        return 0;

}
