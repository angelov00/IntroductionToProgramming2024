#include <iostream>

int main() {
  int year;

  std::cout << "Enter a year" << std::endl;
  std::cin >> year;

  bool isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  if (isLeap) {
    std::cout << "The year is leap" << std::endl;
  } else {
    std::cout << "The year is not leap" << std::endl;
  }
  
  return 0;
}