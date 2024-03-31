#include <iostream>

int main() {
    // Test case 1: Testing with positive numbers
    int num1 = 123456789;
    int num2 = 987654321;
    int sum1 = num1 + num2;
    std::cout << "Sum of " << num1 << " and " << num2 << " is: " << sum1 << std::endl;

    // Test case 2: Testing with negative numbers
    int num3 = -123456789;
    int num4 = -987654321;
    int sum2 = num3 + num4;
    std::cout << "Sum of " << num3 << " and " << num4 << " is: " << sum2 << std::endl;

    // Test case 3: Testing with zero
    int num5 = 0;
    int num6 = 987654321;
    int sum3 = num5 + num6;
    std::cout << "Sum of " << num5 << " and " << num6 << " is: " << sum3 << std::endl;

    return 0;
}