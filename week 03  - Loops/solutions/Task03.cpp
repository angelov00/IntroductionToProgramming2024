#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;

	bool isPrime = true;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}

	// Алтернативно решение, което е по-бързо
	/*bool isPrime = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}*/

	if (isPrime) std::cout << "The number is prime" << std::endl;
	else std::cout << "The number is not prime" << std::endl;
	
	return 0;
}