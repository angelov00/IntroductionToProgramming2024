#include <iostream>

const unsigned MAX_SIZE = 64;
const unsigned ALPHABET_SIZE = 26;

void countLetters(char arr[], unsigned size) {

	int letterCount[ALPHABET_SIZE] = { 0 };

	for (int i = 0; i < size; ++i) {
		++letterCount[arr[i] - 'a'];
	}

	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		if (letterCount[i] > 0) {
			std::cout << (char) (i + 'a') << " : " << letterCount[i] << std::endl;
		}
	}
}

int main() {

	unsigned size = 8;
	char arr[MAX_SIZE] = { 'a', 'b', 'b', 'b', 'd', 'm', 'm', 'y' };

	countLetters(arr, size);
	return 0;

}
