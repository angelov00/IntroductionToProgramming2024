#include <iostream>

const unsigned MAX_SIZE = 64;

bool isSymmetric(const int numbers[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        if (numbers[i] != numbers[size - 1 - i]) {
            return false;
        }
    }
    return true; 
}

int main() {

    int numbers[MAX_SIZE];

    unsigned size;
    std::cin >> size;
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }

    if (isSymmetric(numbers, size)) {
        std::cout << "Symetric!" << std::endl;
    } else {
        std::cout << "Not symetric!" << std::endl;
    }

    return 0;
}
