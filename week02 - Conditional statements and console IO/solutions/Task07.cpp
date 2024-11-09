#include <iostream>

int main() {
    double x1, y1; 
	double x2, y2;
	double x3, y3;

    std::cout << "Enter the coordinates of point 1 (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of point 2 (x2 y2): ";
    std::cin >> x2 >> y2;
    std::cout << "Enter the coordinates of point 3 (x3 y3): ";
    std::cin >> x3 >> y3;

    double area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

    if (area == 0) {
        std::cout << "The points are collinear." << std::endl;
    } else {
        std::cout << "The points are not collinear." << std::endl;
    }

    return 0;
}
