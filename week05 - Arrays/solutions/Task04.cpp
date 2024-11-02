#include <iostream>
#include <climits>

const unsigned MAX_SIZE = 64;

int arrayOscillation(const int numbers[], int size) {
    if (size < 2) return 0; 

    int minElement = INT_MAX;
    int maxElement = INT_MIN;

    for (int i = 0; i < size; ++i) {
        if (numbers[i] < minElement) {
            minElement = numbers[i];
        }
        if (numbers[i] > maxElement) {
            maxElement = numbers[i];
        }
    }

    return maxElement - minElement;
}

int main() {
    int numbers[MAX_SIZE];
    
    unsigned size;
    std::cin >> size;
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }

    int oscillation = arrayOscillation(numbers, size);
    std::cout << "The oscillation of the array is: " << oscillation << std::endl;

    return 0;
}
