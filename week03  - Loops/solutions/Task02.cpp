#include <iostream>

int main() {
    int number;

    int minNum = INT_MAX; // Начална стойност за най-малкото число
    int maxNum = INT_MIN; // Начална стойност за най-голямото число

    std::cin >> number;

    while (number != 0) {
        
        if (number < minNum) {
            minNum = number;
        }
        if (number > maxNum) {
            maxNum = number;
        }
        std::cin >> number;
    }

    // Извеждаме резултатите
    std::cout << "Min number: " << minNum << std::endl;
    std::cout << "Max number: " << maxNum << std::endl;

    return 0;
}
