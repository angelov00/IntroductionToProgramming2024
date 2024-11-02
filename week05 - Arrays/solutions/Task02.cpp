#include <iostream>

double average(int numbers[], int size) {
    if (size == 0) return 0.0; 

    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }

    return sum / size;
}

int main() {
	
	const int size = 5;
    int numbers[size] = {1, 3, 3, 4, 5}; 
   
    double avg = average(numbers, size);
    std::cout << "Средната аритметична стойност е: " << avg << std::endl;

    return 0;
}
