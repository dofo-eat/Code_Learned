
#include "Visitor.h"
#include <sstream>
#include <iostream>
void ExprPointer::Visit(NumberExpr* node)
{
    std::ostringstream os;
    os << node->number;
    this->result = os.str();
    return ;
}
void ExprPointer::Visit(IdExpr* node)
{
	this->result = node->name;
    return ;
}
void ExprPointer::Visit(BinaryExpr* node)
{
	ExprPointer v1, v2;
    node->first->Accept(&v1);
    node->second->Accept(&v2);
    string s;
    switch (node->op) {
        case BinaryOperator::Plus: s = "+"; break;
        case BinaryOperator::Minus: s = "-"; break;
        case BinaryOperator::Multiply: s = "*"; break;
        case BinaryOperator::Divide: s = "/"; break;
    }
    s = s + " " + v1.result + " " + v2.result;
    s = string("(") + s + string(")");
    this->result = s;
    return ;
}
void ExprPointer::Visit(InvokeExpr* node)
{
	string s = node->name;
    for (int i = 0; i < node->arguments.size(); i++) {
        ExprPointer v;
        node->arguments[i]->Accept(&v);
        s = s + " " + v.result;
    }
    s = string("(") + s + string(")");
    this->result = s;
    return ;
}