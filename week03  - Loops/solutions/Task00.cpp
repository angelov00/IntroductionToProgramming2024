#include <iostream>

int main() {
	
	int n;
	
	std::cout << "Enter a number: " << std::endl;
	std::cin >> n;
	
	for(int i = 2; i <= n; i += 2) {
		std::cout << i << std::endl;
	}
	
	return 0;
}