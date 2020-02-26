/*************************************************************************
	> File Name: EP37-3.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月22日 星期日 20时40分00秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1, 1, 0};

void init() {
      int i, j;
    for (i = 2; i <= max_n; i++) {
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
      int h = pow(10, digit - 1);
      int tmp = n;
    for (i = 1; i < digit; i++) {
            tmp /= 10;
            if (is_prime[tmp]) return 0; 
          
    }
      tmp = n;
    for (i = 1; i < digit; i++) {
            tmp %= h;
            if (is_prime[tmp]) return 0; 
            h /= 10;
          
    }
      return 1;

}

int main() {
      init();
      int flag = 11, sum = 0, i;
    for (i = 1; i <= prime[0] && flag; i++) {
            if (prime[i] < 10) continue;
            if (!is_val(prime[i])) continue;
            sum += prime[i];
          
    }
      printf("%d\n", sum);

}
