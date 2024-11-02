#include <iostream>

const unsigned MAX_SIZE = 64;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void removeDuplicates(int arr[], int& size) {
    if (size <= 1) return;

    int uniqueElements[MAX_SIZE];
    uniqueElements[0] = arr[0];
    int uniqueCount = 1;

    for (int i = 1; i < size; ++i) {
        bool isDuplicate = false;

        // Проверяваме дали arr[i] вече съществува в уникалната част на масива
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

void unionArrays(int arr1[], int size1, int arr2[], int size2) {
    int result[MAX_SIZE];
    int resultSize = 0;

    for (int i = 0; i < size1; ++i) {
        result[resultSize++] = arr1[i];
    }

    for (int i = 0; i < size2; ++i) {
        result[resultSize++] = arr2[i];
    }

    removeDuplicates(result, resultSize);

    std::cout << "Union: ";
    printArr(result, resultSize);
}

void intersectionArrays(int arr1[], int size1, int arr2[], int size2) {
    int result[MAX_SIZE];
    int resultSize = 0;

    // Добавяме елементи от arr1, които съществуват в arr2
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {

            if (arr1[i] == arr2[j]) {
                  result[resultSize++] = arr1[i];
            }
        }
    }

    removeDuplicates(result, resultSize);

    std::cout << "Intersection: ";
    printArr(result, resultSize);
}

void symmetricDifference(int arr1[], int size1, int arr2[], int size2) {
    int result[MAX_SIZE];
    int resultSize = 0;

    // Добавяме елементи от arr1, които не съществуват в arr2
    for (int i = 0; i < size1; ++i) {
        bool exists = false;
        for (int j = 0; j < size2; ++j) {
            if (arr1[i] == arr2[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            result[resultSize++] = arr1[i];
        }
    }

    // Добавяме елементи от arr2, които не съществуват в arr1
    for (int i = 0; i < size2; ++i) {
        bool exists = false;
        for (int j = 0; j < size1; ++j) {
            if (arr2[i] == arr1[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            result[resultSize++] = arr2[i];
        }
    }

    std::cout << "Symmetric Difference: ";
    printArr(result, resultSize);
}

int main() {

    int size1 = 5;
    int arr1[MAX_SIZE] = { 1, 2, 3, 4, 5 };

    int size2 = 6;
    int arr2[MAX_SIZE] = { 4, 5, 6, 7, 8, 9 };

    unionArrays(arr1, size1, arr2, size2);
    intersectionArrays(arr1, size1, arr2, size2);
    symmetricDifference(arr1, size1, arr2, size2);

    return 0;
}
