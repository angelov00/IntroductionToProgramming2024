#include <iostream>

int main() {
    double length, width;
	double perimeter;
	double area;

    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length;
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width;

    perimeter = 2 * (length + width);
    area = length * width;

    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;

    return 0;
}
