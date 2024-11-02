#include <iostream>

const unsigned MAX_SIZE = 64;

int sumArray(int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    return sum;
}

int main() {
	
	unsigned size = 5;
    int numbers[MAX_SIZE] = {10, 20, 30, 40, 50}; 

    int sum = sumArray(numbers, size);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
