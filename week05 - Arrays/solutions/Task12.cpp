#include <iostream>

const unsigned MAX_SIZE = 64;

int longestIncreasingSubsequence(int arr[], int size) {
    if (size == 0) {
        return 0;
    }

    int maxLength = 1;      // Дължина на най-дългата нарастваща подредица
    int currentLength = 1;  // Дължина на текущата нарастваща подредица

    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[i - 1]) {  // Ако текущият елемент е по-голям от предишния
            currentLength++;        // Увеличаваме дължината на текущата подредица
            if (currentLength > maxLength) { // Обновяваме maxLength, ако е нужно
                maxLength = currentLength;
            }
        }
        else {
            currentLength = 1; // Рестартираме текущата дължина, ако последователността се прекъсне
        }
    }

    return maxLength;
}

int main() {

    int size = 9;
    int arr[MAX_SIZE] = { 10, 22, 9, 33, 21, 22, 41, 60, 80 };
    

    int length = longestIncreasingSubsequence(arr, size);
    std::cout << "The length of the longest increasing subsequence is: " << length << std::endl;

    return 0;
}
