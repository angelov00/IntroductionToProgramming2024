# Рекурсия

## Дефиниция
Функция се нарича ***рекурсивна***, ако в нейната дефиниция се използва самата функция.

*Рекурсия в математиката:*

$$
n! = \begin{cases} 
1, & \text{ако } n = 0, \\
n \cdot (n-1)!, & \text{ако } n > 0.
\end{cases}
$$


*Рекурсия в програмирането:*
```cpp
int factorial (int n) {
    if(n == 0) return 1; // Базов случай (дъно) на рекурсията
    return n * factorial(n - 1); // Рекурсивно извикване
}
```

### Видове рекурсия
- ***Пряко*** рекурсивна функция - в тялото на функцията се извършва извикване на същата функция
- ***Непряко (косвено)*** рекурсивна функция - функция `A` вика функция `B` , `B` вика `C`, `C` вика отново `A`. 
- Опашкова рекурсия - рекурсивното извикване се осъществява в края и *няма какво друго да се изпълни* след рекурсивното извикване.
## Backtracking

***Backtracking*** (търсене с връщане назад) е общо название на клас от алгоритми, които намират всички или някои решения на изчислителни задачи, по-специално задачи за удовлетворяване на ограничения (constraint satisfaction problems). При този вид алгоритми решението се образува стъпка по стъпка, като за всяка стъпка се проверява дали удовлетворява поставените ограничения. При нарушаване на някое ограничение се отменя последната стъпка и се търси друга възможност (backtrack). При изчерпване на възможностите се отменя предпоследната стъпка и т.н. до получаване на решение или до изчерпване на всички възможности.

#### Задача: *N-Queens Problem*
Да се намери броят на всички възможни начини, по които могат да се поставят $N$ царици на шахматна дъска с размер $N \times N$, така че нито една от тях да не може да атакува друга.

За $N = 4$  има 2 решения: 

*Начин 1:* 
``` 
. Q . .
. . . Q 
Q . . .
. . Q . 
``` 

*Начин 2:*
```
. . Q .
Q . . . 
. . . Q 
. Q . . 
```

*Решение:*
```cpp
bool solve(int board[N][N], int col)
{
    // Всички царици са поставени
    if (col >= N)
        return true;

    // Преминаваме през всички редове в текущата колона
    for (int i = 0; i < N; i++) {
        
        // Проверка дали можем да поставим царицата на текущото място board[i][col]
        if (isSafe(board, i, col)) {
            
            // Поставяме царицата на board[i][col] и маркираме клетката
            board[i][col] = 1;

            // Рекурсивно извикваме фукцията за поставянето на останалите царици
            if (solve(board, col + 1))
                return true;

            // Ако поставянето на царицата в board[i][col] 
            // не води до решение, премахваме я
            board[i][col] = 0; // BACKTRACK
        }
    }

    // Ако не можем да поставим царица в нито един ред 
    // в тази колона, връщаме false
    return false;
}
```

---

# Задачи

# Задача 1.
Напишете функция, която извежда числата от `n` до 1.

---

# Задача 2.
Напишете функция, която намира `n`-тото число на Фибоначи.

---

# Задача 3.
Напишете функция, която връща $x^n$. 

---

# Задача 4.
Напишете функция, която връща $x^n$, но този път използвайте алгоритъма за бързо степенуване. 
[Алгоритъм за бързо степенуване](https://en.wikipedia.org/wiki/Exponentiation_by_squaring)

---
# Задача 5.
Напишете фукцкия, която приема масив от цели числа и цяло число `n` и проверява дали числото се съдържа в масива.

---

# Задача 6.
Напишете функция, която приема масив от цели числа и връща произведението на елементите му. Напишете функцията по два начина.

---

# Задача 7.
Напишете функция, която приема низ и го отпечатва в обратен ред. 

---

# Задача 8.
Напишете функция, която приема низ - израз от скоби и проверява дали е валиден. 
- *Валиден израз:* `()`, `(())()`
- *Невалиден израз:* `((())`, `())(`

---

# Задача 9.
Напишете функция. която приема масив от цели числа и отпечатва всички подмножества на този масив.

---

# Задача 10.
Напишете програма, която решава Судоку. Програмата приема матрица 9х9 и връща решението.

Примерен вход:
```cpp
char board[9][9] = { 
	{5, 3, 0, 0, 7, 0, 0, 0, 0}, 
	{6, 0, 0, 1, 9, 5, 0, 0, 0}, 
	{0, 9, 8, 0, 0, 0, 0, 6, 0}, 
	{8, 0, 0, 0, 6, 0, 0, 0, 3}, 
	{4, 0, 0, 8, 0, 3, 0, 0, 1}, 
	{7, 0, 0, 0, 2, 0, 0, 0, 6}, 
	{0, 6, 0, 0, 0, 0, 2, 8, 0}, 
	{0, 0, 0, 4, 1, 9, 0, 0, 5}, 
	{0, 0, 0, 0, 8, 0, 0, 7, 9} 
}
```

Изход:
```cpp
5 3 4 | 6 7 8 | 9 1 2 
6 7 2 | 1 9 5 | 3 4 8 
1 9 8 | 3 4 2 | 5 6 7
------+-------+------ 
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1 
7 1 3 | 9 2 4 | 8 5 6 
------+-------+------ 
9 6 1 | 5 3 7 | 2 8 4 
2 8 7 | 4 1 9 | 6 3 5 
3 4 5 | 2 8 6 | 1 7 9

```


# Задача 11.

Напишете програма, която приема матрица от символи - лабиринт и отпечатва пътя, по който се излиза от него. 
**Легенда:**
- `'S'` - Начална позиция (Start).
- `'E'` - Изход (Exit).
- `'.'` - Проходим път.
- `'#'` - Непроходима стена.

Примерен вход: 
```cpp
char maze[4][4] = { 
	{'S', '.', '#', '.'}, 
	{'.', '.', '#', '.'}, 
	{'#', '.', '.', '.'}, 
	{'.', '#', '#', 'E'} 
};
```

Изход:
```cpp
(0,0) -> (0,1) -> (1,1) -> (2,1) -> (2,2) -> (3,2) -> (3,3)
```
