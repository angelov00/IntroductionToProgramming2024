#include <iostream>
#include <cmath> // За pow()

int main() {
	
    int binary;
	int decimal = 0;
	int i = 0;
	int remainder;

    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    while (binary != 0) {
		// Вземаме последната цифра от двоичното число
        remainder = binary % 10;  
		
		// Добавяме съответната стойност в десетичната система
        decimal += remainder * pow(2, i); 
		
        binary /= 10; // Премахваме последната цифра
        i++; // Увеличаваме степента на 2-ката
    }

    std::cout << "Decimal: " << decimal << std::endl;

    return 0;
}
