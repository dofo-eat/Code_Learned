/*************************************************************************
	> File Name: visitor.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月20日 星期四 15时22分49秒
 ************************************************************************/
 
#include "visitor.h"
//TODO
void ExpressionPointer::Visit(NumberExpression* node)
{
    int num = node->Value;
    string ret = (num < 0 ? (num = -num, "-") : "");
    do {
        ret = static_cast<char>(num % 10 + '0') + ret;
        num /= 10;
    } while(num);
    this->result += ret;
    this->level = 2;
    return ;
}
 
void ExpressionPointer::Visit(BinaryExpression* node)
{
    ExpressionPointer visFirst, visSecond;
    switch (node->Op) {
        case BinaryOperator::Plus :
        case BinaryOperator::Minus :
            this->level = 0;
            break;
        case BinaryOperator::Multiply :
        case BinaryOperator::Divide :
            this->level = 1;
            break;
    }
    node->First->Accept(&visFirst);
    node->Second->Accept(&visSecond);
    
    if (this->level > visFirst.level) {
        visFirst.result = '(' + visFirst.result + ')';
    }
    this->result += GetOp(node->Op);
    if ((this->level > visSecond.level)
        || ((this->level == visSecond.level)
            && (node->Op == BinaryOperator::Minus || node->Op == BinaryOperator::Divide))
        ) {
        visSecond.result = '(' + visSecond.result + ')';
    }
    this->result = visFirst.result + GetOp(node->Op) + visSecond.result;
    return ;
}


