#include <iostream>

int main() {
   
    double x1, y1, x2, y2;  
    double x3, y3, x4, y4; 

    std::cout << "Enter coordinates of the first rectangle (top-left x1 y1 and bottom-right x2 y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cout << "Enter coordinates of the second rectangle (top-left x3 y3 and bottom-right x4 y4): ";
    std::cin >> x3 >> y3 >> x4 >> y4;
	
    if (x1 >= x4 || x2 <= x3 || y1 <= y4 || y2 >= y3) {
        std::cout << "The rectangles do not overlap." << std::endl;
    } else {
        std::cout << "The rectangles overlap." << std::endl;
    }

    return 0;
}
