#include "gtest/gtest.h" 
#include "Calculator.h"  


TEST(CalculatorTest, Add_HandlesPositiveNumbers) {
    Calculator calc;
    EXPECT_EQ(calc.Add(2, 3), 5);
    EXPECT_EQ(calc.Add(100, 200), 300);
}

TEST(CalculatorTest, Add_HandlesNegativeAndZero) {
    Calculator calc;
    EXPECT_EQ(calc.Add(-5, -10), -15);
    EXPECT_EQ(calc.Add(-5, 5), 0);
    EXPECT_EQ(calc.Add(10, 0), 10);
}



TEST(CalculatorTest, Subtract_HandlesBasicCases) {
    Calculator calc;
    ASSERT_EQ(calc.Subtract(10, 5), 5);
    ASSERT_EQ(calc.Subtract(5, 10), -5);
    ASSERT_EQ(calc.Subtract(0, 0), 0);
}


TEST(CalculatorTest, Multiply_HandlesBasicCases) {
    Calculator calc;
    EXPECT_EQ(calc.Multiply(5, 5), 25);
    EXPECT_EQ(calc.Multiply(10, 0), 0);
    EXPECT_EQ(calc.Multiply(-5, 5), -25);
    EXPECT_EQ(calc.Multiply(-5, -5), 25);
}



TEST(CalculatorTest, Divide_HandlesValidCases) {
    Calculator calc;
   
    EXPECT_DOUBLE_EQ(calc.Divide(10.0, 2.0), 5.0);
    EXPECT_DOUBLE_EQ(calc.Divide(-15.0, 3.0), -5.0);
}


TEST(CalculatorTest, Divide_ThrowsExceptionOnDivideByZero) {
    Calculator calc;
    ASSERT_THROW(calc.Divide(10.0, 0.0), std::runtime_error);
}