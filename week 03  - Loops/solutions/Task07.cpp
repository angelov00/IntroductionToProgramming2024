#include <iostream>

int main() {
    
	unsigned n;
	unsigned reversed = 0;
    std::cin >> n;

    while (n > 0) {
        reversed *= 10;
		reversed += n % 10;
        n /= 10; 
    }
	
    std::cout << reversed << std::endl;

    return 0;
}
