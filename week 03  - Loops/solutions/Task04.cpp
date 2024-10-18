#include <iostream>

int main() {
    unsigned n;
    int factorial = 1;

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    std::cout << "n! = " << factorial << std::endl;

    return 0;
}
