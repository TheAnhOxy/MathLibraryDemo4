#include "MathLibrary.h" 
#include <cmath>
#include <limits>
#include <utility> 

namespace MathLibrary {


 // 1. Kiểm tra số nguyên tố
    bool IsPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
    // 2. Tính tiền điện
    double CalculateElectricBill(double oldReading, double newReading) {
        if (newReading < oldReading || newReading < 0 || oldReading < 0) {
            throw std::invalid_argument("Invalid meter readings provided.");
        }

        const double TIER_1_LIMIT_KWH = 100.0;
        const double PRICE_TIER_1 = 1500.0;
        const double PRICE_TIER_2 = 2500.0;

        double consumption = newReading - oldReading;
        double totalBill = 0.0;

        if (consumption <= TIER_1_LIMIT_KWH) {
            totalBill = consumption * PRICE_TIER_1;
        }
        else {
            totalBill += TIER_1_LIMIT_KWH * PRICE_TIER_1;
            totalBill += (consumption - TIER_1_LIMIT_KWH) * PRICE_TIER_2;
        }
        return totalBill;
    }

    // 3. Giải phương trình bậc 2
    SolutionType SolveQuadratic(double a, double b, double c, double& x1, double& x2) {
        const double epsilon = std::numeric_limits<double>::epsilon();
        if (std::abs(a) < epsilon) { // Phương trình bậc nhất
            if (std::abs(b) < epsilon) {
                return (std::abs(c) < epsilon) ? SolutionType::InfiniteSolutions : SolutionType::NoSolution;
            }
            x1 = x2 = -c / b;
            return SolutionType::OneSolution;
        }
        double delta = b * b - 4 * a * c;
        if (delta < -epsilon) { // delta < 0
            return SolutionType::NoSolution;
        }
        else if (std::abs(delta) < epsilon) { // delta = 0
            x1 = x2 = -b / (2 * a);
            return SolutionType::OneSolution;
        }
        else { // delta > 0
            double sqrt_delta = std::sqrt(delta);
            x1 = (-b + sqrt_delta) / (2 * a);
            x2 = (-b - sqrt_delta) / (2 * a);
            return SolutionType::TwoSolutions;
        }
    }

    // 4. Phân loại tam giác
    TriangleType ClassifyTriangle(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
            return TriangleType::NotATriangle;
        }
        if (a == b && b == c) {
            return TriangleType::Equilateral;
        }
        if (a == b || b == c || a == c) {
            return TriangleType::Isosceles;
        }
        return TriangleType::Scalene;
    }

    // 5. Chuyển đổi nhị phân sang thập phân
    long long BinaryToDecimal(const std::string& binaryString) {
        long long decimalValue = 0;
        long long base = 1;
        for (int i = binaryString.length() - 1; i >= 0; i--) {
            char bit = binaryString[i];
            if (bit == '1') {
                decimalValue += base;
            }
            else if (bit != '0') {
                throw std::invalid_argument("Invalid character in binary string.");
            }
            base *= 2;
        }
        return decimalValue;
    }

    // 6. Kiểm tra năm nhuận
    bool IsLeapYear(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    // 7. Sắp xếp nhanh (QuickSort)
    namespace { // Helper functions chỉ dùng trong file này
        int partition(std::vector<int>& arr, int low, int high) {
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j <= high - 1; j++) {
                if (arr[j] < pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
            std::swap(arr[i + 1], arr[high]);
            return (i + 1);
        }
        void quickSortImpl(std::vector<int>& arr, int low, int high) {
            if (low < high) {
                int pi = partition(arr, low, high);
                quickSortImpl(arr, low, pi - 1);
                quickSortImpl(arr, pi + 1, high);
            }
        }
    }
    void QuickSort(std::vector<int>& arr) {
        if (!arr.empty()) {
            quickSortImpl(arr, 0, arr.size() - 1);
        }
    }
}