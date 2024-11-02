#include <iostream>

void bubbleSortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                //Размяна на елементи, ако не са в правилен ред
                //std::swap(arr[j], arr[j + 1]);  //може да разменяме елементи с std::swap(x1, x2)
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSortAscending(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    const int size = 6;
    int numbers[size] = { 5, -323, 9, 1, 9392, -323236 }; // Примерен масив

    std::cout << "Original array: ";
    printArray(numbers, size);

    // Сортиране по възходящ ред с метод на мехурчето
    bubbleSortAscending(numbers, size);
    std::cout << "Bubble Sort Ascending: ";
    printArray(numbers, size);

    // Сортиране по низходящ ред с метод на мехурчето
    bubbleSortDescending(numbers, size);
    std::cout << "Bubble Sort Descending: ";
    printArray(numbers, size);

    // Сортиране по възходящ ред с метод на вмъкването
    insertionSortAscending(numbers, size);
    std::cout << "Insertion Sort Ascending: ";
    printArray(numbers, size);

    // Сортиране по низходящ ред с метод на вмъкването
    insertionSortDescending(numbers, size);
    std::cout << "Insertion Sort Descending: ";
    printArray(numbers, size);

    return 0;
}
