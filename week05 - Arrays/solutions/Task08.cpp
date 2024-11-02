#include <iostream>

const unsigned MAX_SIZE = 64;

void deleteElement(int arr[], int& size, int index) {
    
    if (index < 0 || index >= size) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    --size;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
	
	int size = 5;
    int numbers[MAX_SIZE] = {1, 2, 3, 4, 5}; 

    std::cout << "Original array: ";
    printArray(numbers, size);

    deleteElement(numbers, size, 2);

    std::cout << "Array after deletion: ";
    printArray(numbers, size);

    return 0;
}
