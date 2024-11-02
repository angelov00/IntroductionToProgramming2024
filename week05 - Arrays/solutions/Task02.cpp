#include <iostream>

const unsigned MAX_SIZE = 64;

double average(int numbers[], unsigned size) {
    if (size == 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }

    return sum / size;
}

int main() {

    unsigned size = 5;
    int numbers[MAX_SIZE] = { 1, 3, 3, 4, 5 };

    double avg = average(numbers, size);
    std::cout << "Average: " << avg << std::endl;

    return 0;
}
