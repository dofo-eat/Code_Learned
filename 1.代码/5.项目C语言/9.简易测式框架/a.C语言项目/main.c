/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月12日 星期日 15时58分13秒
 ************************************************************************/
#include <stdio.h>
#include<haizei_test.h>
#include<unit.h>


__attribute__((constructor))
int haizei_init() {
    printf("hello\n");
    return 0;
}

TEST(test, add_function) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-1, -7), -8);
}


TEST(test1, add_function) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-1, -7), -8);
}
int main(int argc, char *argv[]){
    return RUN_ALL_TESTS();
}
