#pragma once
#include <string>
#include <vector>
#include <stdexcept> 

// --- File MathLibraryAPI.h ---
#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif


namespace MathLibrary {

    // Enum để định nghĩa các loại nghiệm của phương trình bậc 2
    enum class SolutionType { NoSolution, OneSolution, TwoSolutions, InfiniteSolutions };

    // Enum để định nghĩa các loại tam giác
    enum class TriangleType { NotATriangle, Equilateral, Isosceles, Scalene };

    // --- KHAI BÁO CÁC HÀM CỦA THƯ VIỆN ---

    MATHLIBRARY_API bool IsPrime(int num);

    MATHLIBRARY_API double CalculateElectricBill(double oldReading, double newReading);

    MATHLIBRARY_API SolutionType SolveQuadratic(double a, double b, double c, double& x1, double& x2);

    MATHLIBRARY_API TriangleType ClassifyTriangle(double a, double b, double c);

    MATHLIBRARY_API long long BinaryToDecimal(const std::string& binaryString);

    MATHLIBRARY_API bool IsLeapYear(int year);

    // Thuật toán sắp xếp sẽ thay đổi trực tiếp vector đầu vào
    MATHLIBRARY_API void QuickSort(std::vector<int>& arr);
}