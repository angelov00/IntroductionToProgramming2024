#include <iostream>

int main() {
    char ch;

    std::cout << "Enter a character: ";
    std::cin >> ch;

    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        std::cout << ch << " is a letter." << std::endl;
    } else if (ch >= '0' && ch <= '9') {
        std::cout << ch << " is a digit." << std::endl;
    } else {
        std::cout << ch << " is neither a letter nor a digit." << std::endl;
    }

    return 0;
}
