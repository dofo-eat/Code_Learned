/*************************************************************************
	> File Name: 程序设计my_printf.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月08日 星期日 18时46分32秒
 ************************************************************************/
#include<inttypes.h>
#include<stdio.h>
#include<stdarg.h>
#define PUTC(a) putchar(a), ++cnt

int reverse_num(int num, int *temp) {
    int digit = 0;
    do {
        *temp = *temp * 10 + num % 10;
        num /= 10;
        digit += 1;
    } while(num);
        return digit;
}
int output_num(int temp, int digit) {
    int cnt = 0;
    while(digit--) {
        putchar(temp % 10 + '0');
        temp /= 10;
        cnt += 1;
    }
   return cnt;
}

int my_printf(const char *frm, ...){
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for(int i = 0; frm[i]; i++) {//for(int i = 0; i < strlen(frm); i++) {//for(int i = 0; frm[i]; i++)  都是查找到'\0'
        switch(frm[i]) {            
            case '%':{
                switch(frm[++i]) {
                    case'd': {
                        int xx = va_arg(arg, int),temp = 0,digit = 0;
                        uint32_t  x;
                        if(xx < 0) PUTC('-'), x = -xx;
                        x = xx;
                        int num1 = x / 100000, num2 = x % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(num1, &temp1);
                        int digit2 = reverse_num(num2, &temp2);
                        if(digit) digit2 = 5;
                        else digit = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(temp2, digit2);
                      /*  do{
                            temp = temp * 10 + x % 10;
                            x /= 10;
                            digit += 1;
                        } while (x);
                        while(digit--) {
                            PUTC(temp % 10 + '0');
                            temp /= 10;
                        }*/
                    }break;
                    case'%':{
                        PUTC(frm[i]);
                    }
                    case's': {
                        const char *str = va_arg(arg, const char *);
                        for(int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                    }
                }
            }break;
            default: PUTC(frm[i]); break;
        }
    }
    va_end(arg);
    return cnt;
}

int main () {
    int a = 123;
    printf("hello world\n");
    my_printf("hello world\n");
    printf("int (a) = %d\n", a);
    my_printf("int(a) = %d\n", a);
    my_printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("int(a) = %d\n", a);

    return 0;
}
