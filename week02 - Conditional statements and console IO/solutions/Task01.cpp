#include <iostream>

int main() {
	
    int grade;
    std::cout << "Enter a grade from 2 to 6: ";
    std::cin >> grade;

    switch (grade) {
        case 2: std::cout << "Grade: Poor" << std::endl; break;
        case 3: std::cout << "Grade: Average" << std::endl; break;
        case 4: std::cout << "Grade: Good" << std::endl; break;
        case 5: std::cout << "Grade: Very Good" << std::endl; break;
        case 6: std::cout << "Grade: Excellent" << std::endl; break;
        default: std::cout << "Invalid grade! Please enter a number from 2 to 6." << std::endl;
        break;
    }

    return 0;
}
