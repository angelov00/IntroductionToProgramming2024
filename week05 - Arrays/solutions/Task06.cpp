#include <iostream>

int removeDuplicates(int arr[], int size) {
    if (size <= 1) return size;

    int uniqueElements = 1;

    for (int i = 1; i < size; ++i) {
        bool isDuplicate = false;

        //Проверяваме дали arr[i] вече съществува в уникалната част на масива
        for (int j = 0; j < uniqueElements; ++j) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            arr[uniqueElements] = arr[i];
            ++uniqueElements;
        }
    }
    return uniqueElements; 
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    const unsigned size = 9;
    int numbers[] = { 1, 2, 3, 2, 4, 5, 1, 3, 6 }; 

    std::cout << "Original array: ";
    printArray(numbers, size);

    int newSize = removeDuplicates(numbers, size);

    std::cout << "Array after removing duplicates: ";
    printArray(numbers, newSize);

    return 0;
}
