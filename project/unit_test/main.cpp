#include <gtest/gtest.h>

using namespace testing;

TEST(MACROS,MACROS_USAGE)
{
    EXPECT_EQ(10,10);
    EXPECT_EQ(10,11);
}

int main(int argc, char const *argv[])
{
    InitGoogleTest();
    return RUN_ALL_TESTS();
}
