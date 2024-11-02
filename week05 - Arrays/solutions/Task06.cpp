#include <iostream>

const unsigned MAX_SIZE = 64;

void removeDuplicates(int arr[], unsigned& size) {
    if (size <= 1) return;

    int uniqueElements[MAX_SIZE];
    uniqueElements[0] = arr[0];
    int uniqueCount = 1;

    for (int i = 1; i < size; ++i) {
        bool isDuplicate = false;

        //Проверяваме дали arr[i] вече съществува в уникалната част на масива
        for (int j = 0; j < uniqueCount; ++j) {
            if (arr[i] == uniqueElements[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
           uniqueElements[uniqueCount++] = arr[i];
        }
    }

    for (int i = 0; i < uniqueCount; ++i) {
        arr[i] = uniqueElements[i];
    }
    size = uniqueCount;

}

void printArray(int arr[], const unsigned size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    unsigned size = 9;
    int numbers[MAX_SIZE] = { 1, 2, 3, 2, 4, 5, 1, 3, 6 };

    std::cout << "Original array: ";
    printArray(numbers, size);

    removeDuplicates(numbers, size);

    std::cout << "Array after removing duplicates: ";
    printArray(numbers, size);

    return 0;
}
