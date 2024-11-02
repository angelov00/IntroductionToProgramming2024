#include <iostream>

const unsigned MAX_SIZE = 64;

void insertElement(int arr[], int& size, int index, int value) {

    // Проверка дали индексът е валиден
    if (index < 0 || index > size || size >= MAX_SIZE) {
        std::cout << "Invalid index or full array!" << std::endl;
        return;
    }

    // Преместване на елементите над индекса надясно (за да "освободим" място за новия елемент)
    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
    }

    // Вмъкване на новия елемент на определен индекс
    arr[index] = value;
    ++size; // Увеличаване на размера на масива
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int numbers[MAX_SIZE] = { 1, 2, 3, 4, 5 };
    int size = 5;

    std::cout << "Original array: ";
    printArray(numbers, size);

    int index = 2; // Индекс, на който да вмъкнем новото число
    int value = 99; // Число за вмъкване

    insertElement(numbers, size, index, value);

    std::cout << "Array after insertion: ";
    printArray(numbers, size);

    return 0;
}
