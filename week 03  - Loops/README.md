# Цикли

## 1. `for` цикъл

- Използва се за итерации с *известен* брой повторения
- Синтаксис:

```c++

  for (<инициализация>; <условие>; <корекция>) {
      // код за изпълнение
  }

```
  
- **Инициализация**: задава началната стойност на променлива.
- **Условие**: проверява дали цикълът трябва да продължи.
- **Корекция**: актуализира стойността на променливата след всяка итерация.

- Пример: *Извеждане на числата от 1 до 10 на конзолата*

```cpp
  for (int i = 1; i <= 10; i++) {
      std::cout << i << std::endl;
  }
```

## 2. `while` цикъл
- Използва се за итерации с неясен брой повторения, докато условието е вярно.
- Условието се проверява **преди** всяка итерация.
- Синтаксис:

```cpp
  while (условие) {
      // код за изпълнение
  }
```

- Пример: *Броене на цифри на число*

 ```cpp

  int n = 4343;
  int count = 0;
  
  while (n > 0) {
      n /= 10;
      count++;
  }

```

## 3. `do-while` цикъл

- Използва се за итерации с неясен брой повторения, докато условието е вярно.
- Условието се проверява **СЛЕД** всяка итерация (! тоест тялото се изпълнява *ПОНЕ* веднъж)
- Синтаксис:

```cpp
   do {
      // код за изпълнение
  } while (условие);

```

- Пример: *Отгатване на случайно число*

```cpp

int secretNumber = 7;
int guess;

do {
    std::cout << "Отгатнете числото (между 1 и 10): ";
    std::cin >> guess;

} while (guess != secretNumber);

std::cout << "Поздравления! Познахте числото." << std::endl;

```

---

# Задача 1
Напишете програма, която приема цяло число `x` и положително цяло число `n` и връща x^n
Примерен вход:

| Вход  | Изход |
| ----- | ----- |
| 2, 10 | 1024  |
| 3, 7  | 2187  |

---
# Задача 2
Напишете програма, която приема цели числа до въвеждане на 0 и извеждате най-малкото и най-голямото от тях.

---
# Задача 3
Напишете програма. която приема цяло число от конзолата и извежда дали е просто.

---
# Задача 4
Напишете програма, която приема цяло число и извежда стойността на `n!` на конзолата.

---
# Задача 5
Напишете програма, която приема число `n` и отпечатва тригълника на Флойд с височина `n`.
Пример:
Вход: 5
Изход: 
```
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

---
# Задача 6
Напишете програма, която приема цяло число n и отпечатва n-тото число на Фибоначи, Приемаме, че F(1) = 0, F(2) = 1 

| Вход  | Изход |
|-------|-------|
| 5     | 55    |
| 8     | 21    |
| 1     | 0     |

---
# Задача 7
Напишете програма, която приема цяло положително число от потребителя и го изписва в обратен ред на конзолата.

---
# Задача 8
Напишете програма, която въвежда ествествено число и извърпва ротация наляво на цифрите му,

| Вход  | Изход |
|-------|-------|
| 1234  | 2341  |
| 64281 | 42816 |

---
# Задача 9
-Напишете програма, която приема цяло положително число n и извежда на екрана дали то е число на Армстронг. Число на Армстронг е число, което е равно на сумата от собствените си цифри, всяка от които е повдигната на степента на броя на цифрите (https://en.wikipedia.org/wiki/Narcissistic_number).
   * *Пример*: `153` = `1^3 + 5^3 + 3^3` <br>
---

# Задача 10
Напишете програма, която по въведено цяло число в двочина бройна система го превръща в десетична.
  * *Пример*: 
`101010 -> 42` <br>
`10 -> 2` <br>
`1111101 -> 125` <br>

---

# Задача 11*
Напишете програма, която намира колко са различните триъгълници с периметър `P` , за които дължините на страните им, измерени в сантиметри, са цели числа, ако `P` е цяло число.

---

# Задача 12*
Напишете програма, която проверява дали дадено цяло число `n` е палиндром в бройната система с основа `base`.

| Вход (n, base) | Изход |
|----------------|-------|
| 121, 10        | true  |
| 585, 2         | true  |
| 100, 3         | false |
