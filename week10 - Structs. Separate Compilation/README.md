# Структури

## Дефиниция

**Структура (struct) е потребителски тип данни в C++, който позволява групиране на елементи. Елементите, наричани още членове, могат да бъдат от различен тип.**

Синтаксис:
```cpp
struct StructName {
	type member1;
	type member2;
	// ...
}
```

Можем също да дефинираме анонимна структура:

```cpp
struct {
	int x;
	char y;
} varName;
```

*Пример*:
```cpp
#include <iostream>

struct Address {
    char* street;
    char* city;
};

struct Person {
    char* name;
    int age;
    Address address;

    void greet() {
        std::cout << "Hello, my name is " << name << std::endl;
    }
};

```
## Деклариране и инициализация на променлива
```cpp

struct Person{
	char* name;
	int age;
};

Person person1;
person1.name = "Tommy";
person1.age = 66;

Person person2 {"John", 22};
Person person3 = {"Ivan", 50};

```

---

# Разделна компилация
- По-добра организация на кода
- По-бърза компилация
- Повторна употреба на код

## Header Guards (Гардове)
Гардовете в C++ предотвратяват многократно включване на хедър файлове, което би довело до грешки или излишна компилация. Те се имплементират с макроси:

***Синтаксис***:
```cpp

#ifndef HEADER_NAME_H
#define HEADER_NAME_H

// код 

#endif // HEADER_NAME_H

```

*Пример*:
файл `math_utils.h`
```cpp
#ifndef MATH_UTILS_H 
#define MATH_UTILS_H

int add(int a, int b);
int subtract(int a, int b);

#endif
```

`math_utils.cpp
```cpp
#include "math_utils.h" 

int add(int a, int b) {
	return a + b; 
} 

int subtract(int a, int b) { 
	return a - b; 
}
```

`main.cpp`
```cpp

#include "math_utils.h"
#include <iostream>

int main() {
	std::cout << add(4,7) << std::endl;
	std::cout << subtract(111, 30) << std::endl;
}
```



---

# Задачи

# Задача 1

Дефинирайте структура `Point`, която съдържа две целочислени променливи - `x` и `y` - координатите на точката. Напишете функция, която приема две точки и изчислява разстоянието между тях.

---
# Задача 2
Дефинирайте структура `Time`, която съдържа три цели числа - `hours`, `minutes` и `seconds`. Напишете член-функция, която приема друга инстанция от тип `Time` и връща абсолютната разлика в секунди.

---

# Задача 3
Дефинирайте структура `Rectangle`. Напишете член-функция `doOverlap(const Rectangle& other)`, която проверява дали правоъгълниците се пресичат.


---

# Задача 4
Използвайки структурата `Rectangle` от Задача 3, напишете програма, която записва правоъгълниците с лице по-голямо от `x` в двоичен файл.

---

# Задача 5
Дефинирайте структура `Student` с полета `id` и `averageGrade`. Напишете функция, която приема масив от 10 студента и ги сортира по успех (в намаляващ ред).


---

# Задача 6
Напишете програма, която прочита 10 студента от текстов файл и отпечатва id-то и оценката на:
- студентът с най-голям успех
- студентът с най-малък успех
- студентът с оценка медианна оценка

*Пример:*
```
1 5.30
2 3.30
3 4.75
4 4.85
5 6.00
6 3.20
7 5.55
8 4.50
9 5.00
10 3.00

Output: 
Min grade: 10 - 3.00
Max grade: 5 - 6.00
Median grade: 4.80 
```


---

# Задача 7 
Модифицирайте задача 6 да работи за `n` на брой студенти.

---
