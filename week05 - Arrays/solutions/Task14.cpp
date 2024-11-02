#include <iostream>

const unsigned MAX_SIZE = 1024;

int findUniqueElement(const int nums[], int size) {
    int uniqueElement = 0;

    for (int i = 0; i < size; ++i) {
        uniqueElement ^= nums[i];
    }

    return uniqueElement;
}

int main() {

    int size = 5;
    int nums[MAX_SIZE] = { 4, 1, 2, 1, 2 };

    int unique = findUniqueElement(nums, size);

    std::cout << "The single element is: " << unique << std::endl;

    return 0;
}
