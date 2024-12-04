#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int temporary = n;
	int powerOf10 = 1;

	while (temporary > 9) {
		temporary /= 10;
		powerOf10 *= 10;
	}

	int firstDigit = temporary;

	n -= firstDigit * powerOf10;
	n *= 10;
	n += firstDigit;

	std::cout << "Rotated number: " << n << std::endl;
}