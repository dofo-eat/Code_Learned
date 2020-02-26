/*************************************************************************
	> File Name: EP35.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 18时59分09秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#define max_n 1000000

int prime[max_n + 5];
int is_prime[max_n + 5] = {1, 1, 0};

void init() {
      int i, j;
    for (i = 2; i < max_n; i++) {
            if(!is_prime[i]) prime[++prime[0]] = i;
        for (j = 1; j <= prime[0]; j++) {
                  if (prime[j] * i > max_n) break;
                  is_prime[prime[j] * i] = 1;
                  if (i % prime[j] == 0) break;
                
        }
          
    }
      return ;

}

int is_val(int n) {
      int i;
      int digit = floor(log10(n)) + 1;
      int h = (int)pow(10, digit - 1);
      int tmp = n;
    for (i = 1; i < digit; i++) {
            tmp = (tmp % 10) * h + tmp / 10;
            if (is_prime[tmp]) return 0;
          
    }
      return 1;

}

int main() {
      init();
      int sum = 0, i;
    for (i = 1; i <= prime[0]; i++) {
            if (!is_val(prime[i])) continue;
            sum += 1;
          
    }
      printf("%d\n", sum);
      return 0;

}
