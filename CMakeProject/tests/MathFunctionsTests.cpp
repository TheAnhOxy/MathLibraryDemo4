#include "gtest/gtest.h"
#include "MathLibrary.h" 

// Tests for IsPrime
TEST(MathFunctionsTest, IsPrime_CorrectCases) {
    EXPECT_TRUE(MathLibrary::IsPrime(7)) << "7 should be a prime number.";
    EXPECT_TRUE(MathLibrary::IsPrime(2)) << "2 is a prime number.";
    EXPECT_FALSE(MathLibrary::IsPrime(10)) << "10 should not be a prime number.";
    EXPECT_FALSE(MathLibrary::IsPrime(1)) << "1 is not considered a prime number.";
}

TEST(MathFunctionsTest, IsPrime_FailingAndBoundaryCases) {
    
    EXPECT_TRUE(MathLibrary::IsPrime(9)) << "Intentionally failing: 9 is not prime, but we expect it to be true.";

    EXPECT_FALSE(MathLibrary::IsPrime(0)) << "0 is not prime.";
    EXPECT_FALSE(MathLibrary::IsPrime(-5)) << "Negative numbers are not prime.";
}

// Tests for CalculateElectricBill
TEST(MathFunctionsTest, CalculateElectricBill_CorrectCases) {
    EXPECT_DOUBLE_EQ(MathLibrary::CalculateElectricBill(100, 150), 50 * 1500.0);

    EXPECT_DOUBLE_EQ(MathLibrary::CalculateElectricBill(100, 250), 100 * 1500.0 + 50 * 2500.0);

    EXPECT_DOUBLE_EQ(MathLibrary::CalculateElectricBill(100, 100), 0.0);
}

TEST(MathFunctionsTest, CalculateElectricBill_FailingAndBoundaryCases) {

    double expectedWrongBill = 100 * 2500.0;
    double actualBill = MathLibrary::CalculateElectricBill(0, 100);
    EXPECT_DOUBLE_EQ(actualBill, expectedWrongBill) << "Intentionally failing: The bill calculation is wrong.";
    ASSERT_THROW(MathLibrary::CalculateElectricBill(150, 100), std::invalid_argument)
        << "Should throw an exception when new reading is less than old reading.";
}

// Tests for SolveQuadratic
TEST(MathFunctionsTest, SolveQuadratic_CorrectCases) {
    double x1, x2;
    // Two solutions
    EXPECT_EQ(MathLibrary::SolveQuadratic(1, -3, 2, x1, x2), MathLibrary::SolutionType::TwoSolutions);
    EXPECT_DOUBLE_EQ(x1, 2.0);
    EXPECT_DOUBLE_EQ(x2, 1.0);
    // One double root
    EXPECT_EQ(MathLibrary::SolveQuadratic(1, -2, 1, x1, x2), MathLibrary::SolutionType::OneSolution);
    // No solution
    EXPECT_EQ(MathLibrary::SolveQuadratic(1, 2, 3, x1, x2), MathLibrary::SolutionType::NoSolution);
    // Infinite solutions
    EXPECT_EQ(MathLibrary::SolveQuadratic(0, 0, 0, x1, x2), MathLibrary::SolutionType::InfiniteSolutions);
}

TEST(MathFunctionsTest, SolveQuadratic_FailingCases) {
    double x1, x2;
    EXPECT_EQ(MathLibrary::SolveQuadratic(1, -2, 1, x1, x2), MathLibrary::SolutionType::TwoSolutions)
        << "Intentionally failing: Expected two solutions for a double root.";
}


// Tests for ClassifyTriangle
TEST(MathFunctionsTest, ClassifyTriangle_CorrectCases) {
    EXPECT_EQ(MathLibrary::ClassifyTriangle(3, 4, 5), MathLibrary::TriangleType::Scalene);
    EXPECT_EQ(MathLibrary::ClassifyTriangle(5, 5, 5), MathLibrary::TriangleType::Equilateral);
    EXPECT_EQ(MathLibrary::ClassifyTriangle(5, 5, 8), MathLibrary::TriangleType::Isosceles);
    EXPECT_EQ(MathLibrary::ClassifyTriangle(1, 2, 5), MathLibrary::TriangleType::NotATriangle);
}

TEST(MathFunctionsTest, ClassifyTriangle_FailingAndBoundaryCases) {
    EXPECT_EQ(MathLibrary::ClassifyTriangle(5, 5, 8), MathLibrary::TriangleType::Equilateral)
        << " failing: An isosceles triangle is not equilateral.";

    //   (a + b = c)
    EXPECT_EQ(MathLibrary::ClassifyTriangle(3, 4, 7), MathLibrary::TriangleType::NotATriangle)
        << "A degenerate triangle should not be classified as a triangle.";
}

// Tests for BinaryToDecimal
TEST(MathFunctionsTest, BinaryToDecimal_CorrectCases) {
    EXPECT_EQ(MathLibrary::BinaryToDecimal("1111"), 15);
    EXPECT_EQ(MathLibrary::BinaryToDecimal("0"), 0);
    ASSERT_THROW(MathLibrary::BinaryToDecimal("102"), std::invalid_argument)
        << "Should throw an exception for a string with invalid characters.";
}

TEST(MathFunctionsTest, BinaryToDecimal_FailingCase) {
    long long expectedValue = 6;
    long long actualValue = MathLibrary::BinaryToDecimal("101");
    EXPECT_EQ(actualValue, expectedValue) << " failing test case: '101' is 5, not 6.";
}

// Tests for IsLeapYear
TEST(MathFunctionsTest, IsLeapYear_CorrectCases) {
    EXPECT_TRUE(MathLibrary::IsLeapYear(2000));  // Divisible by 400
    EXPECT_TRUE(MathLibrary::IsLeapYear(2024));  // Divisible by 4 but not 100
    EXPECT_FALSE(MathLibrary::IsLeapYear(1900)); // Divisible by 100 but not 400
    EXPECT_FALSE(MathLibrary::IsLeapYear(2023));
}

TEST(MathFunctionsTest, IsLeapYear_FailingCase) {
    EXPECT_TRUE(MathLibrary::IsLeapYear(2023)) << "Intentionally failing: 2023 is not a leap year.";
}

// Tests for QuickSort
TEST(MathFunctionsTest, QuickSort_CorrectCases) {
    // Standard case
    std::vector<int> actualArray = { 5, 1, 4, 2, 8 };
    std::vector<int> expectedArray = { 1, 2, 4, 5, 8 };
    MathLibrary::QuickSort(actualArray);
    ASSERT_EQ(actualArray, expectedArray) << "The array was not sorted correctly.";
    std::vector<int> emptyArray = {};
    MathLibrary::QuickSort(emptyArray);
    ASSERT_TRUE(emptyArray.empty()) << "Sorting an empty array should result in an empty array.";
}

TEST(MathFunctionsTest, QuickSort_FailingCase) {
    std::vector<int> actualArray = { 5, 1, 4, 2, 8 };
    std::vector<int> wrongExpectedArray = { 5, 4, 8, 1, 2 };
    MathLibrary::QuickSort(actualArray);
    ASSERT_EQ(actualArray, wrongExpectedArray) << "Intentionally failing: The expected sorted array is wrong.";
}