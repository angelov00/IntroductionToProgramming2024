#include <iostream>
#include <fstream>

bool isPrime(int n) {

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    int n;
    std::cin >> n;

    std::ofstream outFile("numbers.txt");

    if (!outFile) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    for (int num = 2, counter = n; counter > 0; ++num) {

        if (isPrime(num)) {
            outFile << num << std::endl;
            --counter;
        }
        
    }
    outFile.close();

    return 0;
}
