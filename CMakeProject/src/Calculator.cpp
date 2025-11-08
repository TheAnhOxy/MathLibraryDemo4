#include "Calculator.h" 

int Calculator::Add(int a, int b) {
    return a + b;
}

int Calculator::Subtract(int a, int b) {
    return a - b;
}

int Calculator::Multiply(int a, int b) {
    return a * b;
}

double Calculator::Divide(double a, double b) {
    if (b == 0.0) {

        throw std::runtime_error("Math error: Attempted to divide by Zero");
    }
    return a / b;
}