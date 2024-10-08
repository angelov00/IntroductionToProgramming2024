# Въведение, инсталиране на интегрирана среда за разработка (IDE), първата ни програма

<br>

## 1. Кратко въведение в програмирането
Програмирането е процесът на писане на инструкции, които компютърът изпълнява, за да реши даден проблем, и да извърши определена задача. Компилаторът е инструмент, който "превежда" написания код в машинен код, който компютърът може да изпълни.
## 2. Интегрирана среда за разработка (IDE)
- [Инсталиране на Visual Studio](https://visualstudio.microsoft.com/downloads/)
- [Създаване на проект](https://learn.microsoft.com/en-us/visualstudio/ide/create-new-project?view=vs-2022)
- [Shortcuts for Visual Studio](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf)
## 3. C++

C++ е компилируем, **обектно-ориентиран** програмен език, разработен от Bjarne Stroustrup, **базиран на езика C** и разширява неговите функционалности с концепции за обектно-ориентирано програмиране (ООП). 

---
### Основни типове данни в C++
Променлива е именуван контейнер, който съхранява данни и може да променя стойността си по време на изпълнението на програмата. Константа, от друга страна, е **променлива** с фиксирана стойност, която не може да бъде променяна след инициализацията.

- **Скалaрни**:
  - `short/int/long int/long long` – цели числа със знак;
  - `unsigned` – цели положителни числа;
  - `float/double` – реални числа с двойна точност;
  - `char` – символ;
  - `bool` – булева стойност (true/false);
  - `enum` – изброен;
  - `void` – празен тип;
  - `auto` 
- **Съставни** - масив, низ, вектор.

--- 
### Условни оператори и проверки в C++

Условните оператори и проверки в C++ позволяват изпълнението на различни блокове код в зависимост от изпълнението на дадени условия.

### Условни оператори (`if`, `else if`, `else`)

- `if` операторът се използва за изпълнение на блок код, ако условието е вярно (true).
- `else if` се използва за добавяне на допълнителни проверки.
- `else` операторът се изпълнява, ако всички предишни условия са грешни (false).
##### Пример:
```cpp
int x = 10;

if (x > 20) {
    std::cout << "x е по-голямо от 20\n";
} else if (x == 10) {
    std::cout << "x е равно на 10\n";
} else {
    std::cout << "x е по-малко от 20\n";
}
```

---
### `switch` оператор
Използва се за проверка на множество стойности на една променлива:
##### Пример:
```cpp
switch (day) {
    case 1: std::cout << "Понеделник"; break;
    case 2: std::cout << "Вторник"; break;
    ...
    case 7: std::cout << "Неделя"; break;
    default: std::cout << "Невалиден ден";
}
```

---
#### Тернарен оператор
Тернарният оператор е кратък начин за писане на условни изрази:

`условие ? стойност_ако_условието_е_вярно : стойност_ако_условието_е_грешно`;
##### Пример:
```cpp
int max = (a > b) ? a : b;
```

# Задачи:

---

## Задача 1
Да се инсталира среда за програмиране

---
## Задача 2
Напишете задача, която отпечатва "Hello world!" на конзолата.

```cpp
// Това е коментар
/*
===================
Това също е коментар
===================
*/

// Директива, която указва на предпроцесора да включи съдържанието на хедъра
// iostream – хедър дефинира стандартните входно-изходни операции
#include <iostream>

// Главна функция
int main () { // тяло и разположение на скоби

	std::cout << "Hello world!"; // Извежда "Hello world!"
	return 0; // Връща стойност 0
}

```

--- 
## Задача 3
Напишете програма, която събира две числа
```cpp
#include <iostream> // Включваме библиотека за вход и изход

int main() {
    int a, b; // Декларираме две цели числа (int)
    
    std::cout << "Въведете първото число: "; // Отпечатваме съобщение
    std::cin >> a; // Четем стойността на първото число от потребителя
    
    std::cout << "Въведете второто число: "; // Отпечатваме съобщение
    std::cin >> b; // Четем стойността на второто число от потребителя
    
    int sum = a + b; // Изчисляваме сумата на двете числа
    
    std::cout << "Сумата на двете числа е: " << sum << std::endl; // Отпечатваме резултата
    
    return 0; // Връщаме 0, което означава, че програмата е приключила успешно
}

```

---
## Задача 4
Напишете програма, която проверява дали едно число е четно или нечетно.
```cpp
#include <iostream> // Включваме библиотека за вход и изход

int main() {
    int num; // Декларираме цяло число (int)
    
    std::cout << "Въведете число: "; // Отпечатваме съобщение
    std::cin >> num; // Четем числото от потребителя
    
    // Проверяваме дали числото е четно
    if (num % 2 == 0) {
        std::cout << num << " е четно число." << std::endl; // Ако числото е четно, отпечатваме съответното съобщение
    } else {
        std::cout << num << " е нечетно число." << std::endl; // Ако числото е нечетно, отпечатваме съответното съобщение
    }
    
    return 0; // Връщаме 0, което означава, че програмата е приключила успешно
}
```

