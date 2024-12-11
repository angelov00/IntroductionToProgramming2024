#include <iostream>

// Task 1
bool isPowerOfTwo(int n) {
    if (n < 0) return false;

    return (n & (n - 1)) == 0;
}

// Task 2
int nextPowerOfTwo(int n) {
    if (isPowerOfTwo(n)) return n;

    int power = 1;
    while (power < n) {
        power <<= 1;
    }
    return power;
}

// Task 3
int previousPowerOfTwo(int n) {
    if (n <= 1) return 0;  

    int power = 1;
    while (power <= n) {
        power <<= 1;  
    }
    return power >> 1; 
}

// Task 4
int getKthBit(int n, int k) {
    return (n >> (k - 1)) & 1;
}

// Task 5
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

// Task 6
int swapBits(int n, int i, int j) {
    int bit1 = (n >> i) & 1;
    int bit2 = (n >> j) & 1;

    if (bit1 != bit2) {
        n ^= (1 << i);
        n ^= (1 << j);
    }
    return n;
}

// Task 7
int xorWithoutOperator(int a, int b) {
    return (a | b) & ~(a & b);
}

// Task 8
int reverseBits(int n) {
    int result = 0;
    while (n > 0) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

int main() {

    std::cout << "Task 1: Is 16 a power of 2? " << (isPowerOfTwo(16) ? "Yes" : "No") << std::endl;
    std::cout << "Task 2: Next power of 2 after 19: " << nextPowerOfTwo(19) << std::endl;
    std::cout << "Task 3: Previous power of 2 before 55: " << previousPowerOfTwo(55) << std::endl;
    std::cout << "Task 4: 3rd bit of 13: " << getKthBit(13, 3) << std::endl;
    std::cout << "Task 5: Number of 1-bits in 29: " << countSetBits(29) << std::endl;
    std::cout << "Task 6: Swap bits at positions 1 and 3 in 22: " << swapBits(22, 1, 3) << std::endl;
    std::cout << "Task 7: XOR of 5 and 3 without operator: " << xorWithoutOperator(5, 3) << std::endl;
    std::cout << "Task 8: Reverse bits of 13: " << reverseBits(13) << std::endl;

    return 0;
}
