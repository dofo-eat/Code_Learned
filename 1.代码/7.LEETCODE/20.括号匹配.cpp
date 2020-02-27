/*************************************************************************
	> File Name: 20.括号匹配.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月27日 星期四 19时23分28秒
 ************************************************************************/
bool isValid(char * s){
    int len = strlen(s), top = -1, flag = 1;
    char *stack = (char *)malloc(sizeof(char) *len);
    while(s[0]) {
        switch(s[0]) {
            case '(':stack[++top] = s[0];break;
            case '[':stack[++top] = s[0];break;
            case '{':stack[++top] = s[0];break;
            case')':flag = (top != -1 && stack[top--] == '(');break;
            case']':flag = (top != -1 && stack[top--] == '[');break;
            case'}':flag = (top != -1 && stack[top--] == '{');break;
        }
        if(flag == 0) break;
        s++;
    }
    free(stack);
    return(flag &&top == -1);
}
