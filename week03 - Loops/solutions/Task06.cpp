#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;

	unsigned finalNumber;

	unsigned prev2 = 0;
	unsigned prev1 = 1;
	for (i = 2; i <= n; i++) {
		unsigned currentFibonacci = prev1 + prev2;
		prev2 = prev1;
		prev1 = currentFibonacci;
	}

	std::cout << "Fibonacci number: " << prev1 << std::endl;
}