#include <iostream>

int main() {
  int a, b, c;

  std::cout << "Enter side a" << std::endl;
  std::cin >> a;

  std::cout << "Enter side b" << std::endl;
  std::cin >> b;

  std::cout << "Enter side c" << std::endl;
  std::cin >> c;


  if (a + b > c && a + c > b && b + c > a) {
    std::cout << "Valid sides!" << std::endl;
  } else {
    std::cout << "Invalid sides!" << std::endl;
  }
  
  return 0;
}