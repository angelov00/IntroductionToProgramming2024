#include <iostream>

const int MAX_SIZE = 200; 

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[], int& resultSize) {
    // i - брояч на първия масив
    // j - брояч на втория масив
    // k - брояч на слетия масив
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        }
        else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    while (j < size2) {
        result[k++] = arr2[j++];
    }

    resultSize = k; 
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int firstSize = 5;
    int secondSize = 6;
    int arr1[MAX_SIZE] = { 1, 3, 5, 7, 9 }; 
    int arr2[MAX_SIZE] = { 2, 4, 6, 8, 10, 58}; 

    int resultSize = firstSize + secondSize;
    int result[MAX_SIZE]; 

    mergeSortedArrays(arr1, firstSize, arr2, secondSize, result, resultSize);

    std::cout << "Merged Sorted Array: ";
    printArray(result, resultSize);

    return 0;
}
