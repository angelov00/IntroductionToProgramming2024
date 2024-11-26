# Файлове и потоци

![Йерархията на потоците в C++](https://iq.opengenus.org/content/images/2022/12/pic1-1.png)


**ПОТОК** - Редица от байтове, които се движат в една посока. Потокът може да бъде **входен** или **изходен**.
Пример за входен поток - `cin`
Пример за изходен поток - `cout`
## Декларация на файл
- за четене
  `std::ifstream iFileName` 
- за вмъкване
  `std::ofstream oFileName`
- за извличане и вмъкване
  `std::fstream ioFileName`

## Видове файлове
- Текстови файлвое
- Двочини файлове
## Режим на достъп

| Member Constant | Stands For     | Access                                                                                   |
| --------------- | -------------- | ---------------------------------------------------------------------------------------- |
| ios::in         | input          | File open for reading: the internal stream buffer supports input operations.             |
| ios::out        | output         | File open for writing: the internal stream buffer supports output operations.            |
| ios::binary     | binary         | Operations are performed in binary mode rather than text.                                |
| ios::ate        | at end         | The output position starts at the end of the file.                                       |
| ios::app        | append         | All output operations happen at the end of the file, appending to its existing contents. |
| ios::trunc      | truncate       | Any contents that existed in the file before it is open are discarded.                   |
| ios::nocreate   | Do not create  | Does not allow to create new file if it does not exist.                                  |
| ios::noreplace  | Do not replace | Does not replace old file with new file.                                                 |
## Таблица с методите на входно-изходните потоци:

| Член-функция/Оператор                                             | Описание                                                                                                      |
| ----------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| `istream& operator>>(T& value)`                                   | Оператор за извличане (вход) на данни от поток в променлива `value`.                                          |
| `ostream& operator<<(const T& value)`                             | Оператор за запис (изход) на данни от променлива `value` в поток.                                             |
| `istream& get(char& c)`                                           | Чете един символ от входния поток и го записва в променливата `c`.                                            |
| `istream& get(char* buffer, streamsize n)`                        | Чете до `n` символа в `buffer` от входния поток, като спира при нов ред или достигане на `n`.                 |
| `ostream& put(char c)`                                            | Записва един символ в изходния поток.                                                                         |
| `istream& read(char* buffer, streamsize n)`                       | Чете точно `n` байта в `buffer` от входния поток.                                                             |
| `ostream& write(const char* buffer, streamsize n)`                | Записва точно `n` байта от `buffer` в изходния поток.                                                         |
| `istream& ignore(streamsize n = 1, int delim = EOF)`              | Игнорира `n` символа или до среща на `delim` от входния поток.                                                |
| `istream& getline(char* buffer, streamsize n, char delim = '\n')` | Чете символи от входния поток и ги записва в `buffer`, докато не срещне `delim` или достигне `n` символа.     |
| `istream& peek()`                                                 | Връща следващия символ от входния поток без да го премахва.                                                   |
| **Позиция в поток:**                                              |                                                                                                               |
| `istream& seekg(streamoff p, ios::seekdir r)`                     | Премества указателя за четене в потока с `p` байта спрямо позицията `r` (`ios::beg`, `ios::cur`, `ios::end`). |
| `ostream& seekp(streamoff p, ios::seekdir r)`                     | Премества указателя за запис в потока с `p` байта спрямо позицията `r` (`ios::beg`, `ios::cur`, `ios::end`).  |
| `streampos tellg()`                                               | Връща текущата позиция на указателя за четене в потока.                                                       |
| `streampos tellp()`                                               | Връща текущата позиция на указателя за запис в потока.                                                        |
| **Състояние на поток: **                                          |                                                                                                               |
| `bad()`                                                           | Връща `true`, ако е възникнала фатална грешка при потока.                                                     |
| `fail()`                                                          | Връща `true`, ако е възникнала грешка при операциите с потока (например, невалиден формат).                   |
| `eof()`                                                           | Връща `true`, ако потокът е достигнал края на файла при четене.                                               |
| `good()`                                                          | Връща `true`, ако потока е в добро състояние (без грешки или достигнат край на файл).                         |
| `clear()`                                                         | Изчиства флаговете на потока и го връща в добро състояние.                                                    |
| `flush()`                                                         | Изпразва буфера на изходния поток, като записва всички данни.                                                 |

*Малко примери:*

*Четене от файл*
```cpp

#include <iostream>
#include <fstream>  // Необходим за работа с файлове

int main() {

    std::ofstream outFile("example.txt");  // Файлът ще бъде създаден, ако не съществува

    if (!outFile) {  // Проверка дали файлът е отворен успешно
        std::cerr << "Cannot open file!" << std::endl;
        return 1;
    }

    // Записване на текст в файла
    std::outFile << "Hello world!" << std::endl;
    std::outFile << "An example for writing in a file" << std::endl;

    // Затваряне на файла
    std::outFile.close();

    return 0;
}

```

*Писане във файл*
```cpp
#include <iostream>
#include <fstream>  // Необходим за работа с файлове
#include <string>   // За работа с низове

using namespace std;

int main() {

    std::ifstream inFile("example.txt");  // Отваряне на съществуващ! текстов файл

    if (!inFile) {  // Проверка дали файлът е отворен успешно
        std::cerr << "Не може да се отвори файлът!" << std::endl;
        return 1;
    }

    std::string line;
    
    // Четене на съдържанието на файла ред по ред
    while (getline(inFile, line)) {
        std::cout << line << std::endl;  // Извеждане на реда на екрана
    }

    // Затваряне на файла
    inFile.close();

    return 0;
}

```

*Двочни файлове:*
```cpp
#include <iostream>
#include <fstream>

int main() {
    const int size = 5;
    int numbers[size] = {10, 20, 30, 40, 50};  // Масив от числа за запис
    int readNumbers[size];                    // Масив за четене от файл

    // 1. Записване на масива в двоичен файл
    std::ofstream outFile("binary_data.bin", std::ios::binary | std::ios::out); // Отваряне в двоичен режим
    if (!outFile) {
        std::cerr << "Cannot open file!" << std::endl;
        return 1;
    }

    // Записване на целия масив
    outFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));

    // Проверка за успешно записване
    if (!outFile) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    outFile.close();

    // 2. Четене на масива от двоичния файл
    std::ifstream inFile("binary_data.bin", std::ios::binary | std::ios::in); // Отваряне в двоичен режим
    if (!inFile) {
        std::cerr << "Cannot open file!" << std::endl;
        return 1;
    }

    // Четене на целия масив
    inFile.read(reinterpret_cast<char*>(readNumbers), sizeof(readNumbers));

    // Проверка за успешно четене
    if (!inFile) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    inFile.close();

    // 3. Извеждане на прочетените данни
    std::cout << "Data: ";
    for (int i = 0; i < size; ++i) {
        std::cout << readNumbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

```

---
# Задачи:

# Задача 1

Създайте програма, която записва първите `n` числа в текстов файл, като всяко бъде на нов ред.

---

# Задача 2

Напишете програма, която прочита 10 числа, разделени с интервал, от файл и намира тяхната сума.

---
# Задача 3

Създайте програма, която чете символи от текстов файл (по едно име на ред) и ги записва в друг файл, като всяка главна буква се превръща в малка и обратното.

---
# Задача 4

Напишете програма, която записва 10 символа, въведени от потребителя, в текстов файл. Прочетете файла и изведете броя на гласните букви, които съдържа.

---
# Задача 5

Напишете програма, която чете матрица 4х4 от текстов файл (числата от един ред са разделени с интервал) и извежда абсолютната разлика между главния и вторичния диагонал.

---
# Задача 6

Създайте програма, която записва динамичен масив от цели числа в двоичен файл. Размерът на масива и елементите му се задават от потребителя. След това прочетете масива от файла и:

1. Изведете съдържанието му.
2. Изчислете и изведете средноаритметичното на елементите.
3. Изведете най-големия и най-малкия елемент

---
# Задача 7

Напишете програма, която чете матрица с произволни размери от двоичен файл. Програмата трябва:

1. Да изчисли и изведе сумата на елементите на главния диагонал (ако матрицата е квадратна).
2. Да изведе броя на всички отрицателни числа в матрицата.

---

