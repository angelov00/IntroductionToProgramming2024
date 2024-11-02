#include <iostream>
#include <cmath>

int abs(int x) {
	return (x > 0) ? x : -x;
}

int sumToN(int n) {
	//Това е формулата за аритметична прогресия
	return (n * (n + 1)) / 2;
}

int countOccurrence(int n, int x) {
	int count = 0;
	for (int i = n; i > 0; i /= 10) {
		if (i % 10 == x) ++count;
	}
	return count;
}

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

void printPrimesInInterval(int a, int b) {
	for (int i = a; i < b; ++i) {
		if (isPrime(i)) std::cout << i << " ";
	}
}

bool isPalindrome(int n) {
	if (n < 0) return false;

	int reversed = 0;
	for (int i = n; i > 0; i /= 10) {
		reversed = (reversed * 10) + i % 10;
	}

	return n == reversed;
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int factorial(int n) {
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}

int binomial(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

bool isPerfect(int n) {
	
	if (n <= 1) return false;

	unsigned sumOfDivisors = 0;

	// Сбора на делителите на перфектното число не включва самото число, така че ще циклим не до самото n, а до n - 1
	// Затова неравенството в условието на цикъла е строго
	for (unsigned i = 1; i < n; i++) {
		if (n % i == 0) sumOfDivisors += i;
	}

	return n == sumOfDivisors;
}

void printPerfectNumbersInInterval(int a, int b) {
	for (int i = a; i < b; ++i) {
		if (isPerfect(i)) std::cout << i << " ";
	}
}

void printPrimePairs(int n) {
	//итерацията е само до n/2, тъй като очевидно a + b е същото като b + a
	for (int a = 2; a <= n / 2; ++a) {
		int b = n - a;
		if (isPrime(a) && isPrime(b)) {
			std::cout << "<" << a << ", " << b << ">" << std::endl;
		}
	}
}

int rotateNumber(int n) {
	int temporary = n;
	int powerOf10 = 1;

	while (temporary > 9) {
		temporary /= 10;
		powerOf10 *= 10;
	}

	int firstDigit = temporary;
	n -= firstDigit * powerOf10;  // Премахваме първата цифра
	n = n * 10 + firstDigit;      // Добавяме първата цифра в края

	return n;
}

// Функция за проверка дали числото е кръгово просто
bool isCircularPrime(int n) {
	int rotationsCount = 0;
	int temp = n;

	// Изчисляваме броя на цифрите, който ще бъде равен на броя на ротациите
	while (temp > 0) {
		rotationsCount++;
		temp /= 10;
	}

	temp = n; // Възстановяваме `temp` към оригиналната стойност на `n`

	// Проверяваме всяка ротация на числото
	for (int i = 0; i < rotationsCount; ++i) {
		// Проверка за 0: ако временно число съдържа 0, не може да е кръгово просто
		if (temp % 10 == 0) return false;
		if (!isPrime(temp)) return false; 
		temp = rotateNumber(temp); 
	}

	return true;
}

void printCircularPrimesInInterval(int a, int b) {
	for (int i = a; i <= b; ++i) { 
		if (isCircularPrime(i)) std::cout << i << " ";
	}
	std::cout << std::endl;
}

unsigned transformToBase10(unsigned x, unsigned y) {
	unsigned result = 0;
	unsigned powOfY = 1;
	while (x) {
		result += powOfY * (x % 10);
		powOfY *= y;
		x /= 10;
	}
	return result;
}

unsigned transformFromBase10(unsigned x, unsigned z) {
	unsigned powOf10 = 1;
	unsigned result = 0;
	while (x) {
		result += powOf10 * (x % z);
		x = x / z;
		powOf10 *= 10;
	}
	return result;
}

unsigned transformNumber(unsigned x, unsigned y, unsigned z) {

	// transformToBase10(x, y) връща числото x от y-ична в 10-ична бройна система
	// transformFromBase10(x, z) връща числото x от 10-ична в z-ична бройна система
	return transformFromBase10(transformToBase10(x, y), z);
}
