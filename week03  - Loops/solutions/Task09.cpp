#include <iostream>

int main() {

	unsigned n;
	std::cin >> n;

	unsigned digitCount = 0;
	unsigned temporary = n;

	// Edge case: n == 0
	if (temporary == 0) digitCount = 1;
	else {
		while (temporary > 0) {
			digitCount++;
			temporary /= 10;
		}
	}

	unsigned sum = 0;
	temporary = n;
	while (temporary > 0) {
		unsigned current = 1;
		for (int i = 1; i <= digitCount; i++) {
			current = current * (temporary % 10);
		}
		sum += current;
		temporary /= 10;
	}

	std::cout << (sum == n ? "It's an Armstrong number" : "It's not an Armstrong number") << std::endl;
}