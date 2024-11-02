#include <iostream>
#include <algorithm>

const unsigned MAX_SIZE = 64;

//Първи начин
int majorityElement(int nums[], int size) {
    std::sort(nums, nums + size);
    return nums[size / 2];
}

//Втори начин, който е по-бърз
int majorityElement2(int nums[], int size) {
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate; 
}

int main() {
    
    int size1 = 7;
    int nums1[MAX_SIZE] = { 2, 2, 1, 1, 1, 2, 2 }; 

    int size2 = 5;
    int nums2[MAX_SIZE] = { 3, 3, 3, 6, 1 };

    int majority1 = majorityElement(nums1, size1);
    int majority2 = majorityElement2(nums2, size2);

    std::cout << "The majority element is: " << majority1 << std::endl;
    std::cout << "The majority element is: " << majority2 << std::endl;

    return 0;
}
