#include "../lib/mymathfunc.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>

using namespace std;
MyMathFunc func_test;

class MyMathFuncTest : public ::testing::Test {
protected:
	virtual void SetUp() { }
	virtual void TearDown() {}
public:
    static const double a = 47.98;
    static const double b = 18.25;
};

TEST_F(MyMathFuncTest, test_addition)
{
    EXPECT_DOUBLE_EQ(66.23,func_test.add(a, b));
}

TEST_F(MyMathFuncTest, test_subtraction)
{
    EXPECT_DOUBLE_EQ(29.73,func_test.subtract(a, b));
}
TEST_F(MyMathFuncTest, test_division)
{
    EXPECT_NEAR(2.62904, func_test.divide(a, b), 0.0000011);
}
TEST_F(MyMathFuncTest, test_multiply)
{
    EXPECT_DOUBLE_EQ(875.635,func_test.multiply(a, b));
}
TEST_F(MyMathFuncTest, test_square)
{
    EXPECT_DOUBLE_EQ(2302.0804,func_test.square(a));
    EXPECT_DOUBLE_EQ(333.0625,func_test.square(b));
}
int main(int argc, char * argv[])
{
	/*The method is initializes the Google framework and must be called before RUN_ALL_TESTS */
	::testing::InitGoogleTest(&argc, argv);

	/*RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro.
	It's must be called only once in the code because multiple calls lead to conflicts and,
	therefore, are not supported.
	*/
	return RUN_ALL_TESTS();
}