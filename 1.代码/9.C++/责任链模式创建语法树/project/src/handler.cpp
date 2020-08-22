#include "handler.h"
#include <cstdlib>
#include <functional>

auto InRange = [](int b, int e) {
    return [=](int x) -> bool {
        return x <= e && x >= b;
    };
};

auto OR = [](std::function<bool(int)> f, std::function<bool(int)> g) {
    return [=](int x) -> bool {
        return f(x) || g(x);
    };
};

auto IsDigit = InRange('0', '9');
auto IsLittle = InRange('a', 'z');
auto IsUpper = InRange('A', 'Z');
auto IsAlpha = OR(IsLittle, IsUpper);

#include <iostream>

bool IdHandler::Test(string token, bool forInvoke)
{
	if (!IsAlpha(token[0]) || forInvoke) return false;
    for (int i = 1; i < token.size(); i++) {
        if (!IsDigit(token[i]) && !IsAlpha(token[i])) return false;
    }
    return true;
}
shared_ptr<Expr> IdHandler::IdFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<IdExpr> p = make_shared<IdExpr>();
    p->name = token;
    return p;
}

shared_ptr<Expr> NumberHandler::NumberFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	int num = atoi(token.c_str());
	shared_ptr<NumberExpr> p = make_shared<NumberExpr>();
    p->number = num;
    return p;
}
bool NumberHandler::Test(string token, bool forInvoke)
{
	if (forInvoke) return false;
    for (int i = 0; i < token.size(); i++) {
        if (!IsDigit(token[i])) return false;
    }
    return true;
}

bool BinaryHandler::Test(string token, bool forInvoke)
{
	if (forInvoke || token.size() != 1) return false;
    switch (token[0]) {
        case '+':
        case '-':
        case '*':
        case '/':
        return true;
    }
    return false;
}
shared_ptr<Expr>BinaryHandler::BinaryFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<BinaryExpr> p = make_shared<BinaryExpr>();
    switch (token[0]) {
        case '+': p->op = BinaryOperator::Plus; break;
        case '-': p->op = BinaryOperator::Minus; break;
        case '*': p->op = BinaryOperator::Multiply; break;
        case '/': p->op = BinaryOperator::Divide; break;
    }
    p->first = arguments[0];
    p->second = arguments[1];
    arguments.erase(arguments.begin());
    arguments[0] = p;
    if (arguments.size() > 1) {
        return CreateExpr(token, arguments);
    }
    return arguments[0];
}

shared_ptr<Expr> InvokeHandler::InvokeFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<InvokeExpr> p = make_shared<InvokeExpr>();
    p->name = token;
    for (int i = 0; i < arguments.size(); i++) {
        p->arguments.push_back(arguments[i]);
    }
    return p;
}
bool InvokeHandler::Test(string token, bool forInvoke)
{
	if (!IsAlpha(token[0]) || forInvoke == false) return false;
    for (int i = 1; i < token.size(); i++) {
        if (!IsDigit(token[i]) && !IsAlpha(token[i])) return false;
    }
    return true;
}
