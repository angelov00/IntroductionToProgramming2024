#include <iostream>

int main() {
  int n;

  std::cout << "Enter n" << std::endl;
  std::cin >> n;

  // броя числа от 1 до n, които дават остатък 2 при деление на 5
  int k = n / 5;
  if(n % 5 >= 2) k++;
  
  // Пример -  n = 21, числата, които дават остатък 2 при деление на 5, са -> 2, 7, 12, 17
  // 1. Забелязваме, че това е аритметична прогресия с първи член a1 = 2, d = 5 и общо k на брой члена
  // 2. Намираме k-тия член на тази прогресия от формулата ak = (k - 1) * d + a1
  // 3. За да намерим сумата от първия до k-тия член използваме формулата Sk = k * (a1 + ak) / 2

  int a1 = 2;

  int ak = (k - 1) * 5 + a1;
  int sum = k * (a1 + ak) / 2;

  std::cout << "SUM: " << sum << std::endl;
  return 0;
}