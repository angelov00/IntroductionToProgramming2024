#include <iostream>

int main() {
    double celsius;
	double result;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    result = celsius * 1.8 + 32;
	
    std::cout << celsius << "°C is equal to " << result << "°F." << std::endl;

    return 0;
}
