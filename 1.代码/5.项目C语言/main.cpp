/*************************************************************************
	> File Name: main.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年01月12日 星期日 15时23分16秒
 ************************************************************************/

#include<iostream>
#include<gtest/gtest.h>
#include"unit.h"
using namespace std;

TEST(test, add_function) {
    EXPEXT_EQ(add(3, 4), 7);
    EXPEXT_EQ(add(0, 0), 0);
    EXPEXT_EQ(add(-1, -7), -8);
}

int main (int argc, char &+*argv[]) {
    ::testint::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
    return 0;
}
