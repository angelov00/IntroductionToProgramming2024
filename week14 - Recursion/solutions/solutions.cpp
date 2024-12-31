#include <iostream>

int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {

    if(n == 1) return 0;
    if(n == 2) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int pow(int x, int n) {

    if(n < 0) return 1 / pow(x, -n);
    if(n == 0) return 1;

    return x * pow(x, n - 1);
}

int fastPow(int x, int n) {

    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else if (n % 2 == 0) {
        int halfPower = fastPow(x, n / 2);
        return halfPower * halfPower;
    } else {
        int halfPower = fastPow(x, (n - 1) / 2);
        return x * halfPower * halfPower;
    }
}

bool contains(int* arr, int size, int x) {

    if(size == 0) return false;

    return arr[size - 1] == x || contains(arr, size - 1, x);
}

int findProduct(int* arr, int size) {
    
    if(size == 0) return 1;
    return arr[size - 1] * findProduct(arr, size - 1);
}

int findProduct2Helper(int* arr, int size, int index) {

    if(index == size) return 1;

    return arr[index] * findProduct2Helper(arr, size, index + 1);
}

int findProduct2(int* arr, int size) {
    return findProduct2Helper(arr, size, 0);
}

void printReversedString(const char* str) {
    
    if(*str == '\0') return;
    
    printReversedString(str + 1);
    std::cout << *str;
}

bool isValidExpressionHelper(const char* expr, int index, int count) {

    if (expr[index] == '\0') {
        // Ако няма отворени скоби в края, изразът е валиден
        return count == 0;
    }

    char current_char = expr[index];

    if (current_char == '(') {
        // Срещаме отваряща скоба, увеличаваме броя на отворените скоби
        return isValidExpressionHelper(expr, index + 1, count + 1);
    }
    else if (current_char == ')') {
        // Срещаме затваряща скоба, намаляваме броя на отворените скоби
        if (count == 0) {
            // Ако няма отваряща скоба, която да затворим, изразът е невалиден
            return false;
        }
        return isValidExpressionHelper(expr, index + 1, count - 1);
    }

    // Ако символът не е скоба, продължаваме нататък
    return isValidExpressionHelper(expr, index + 1, count);
}

bool isValidExpression(const char* expr) {
    return isValidExpressionHelper(expr, 0, 0);
}

void printSubsetsHelper(int arr[], int n, int index, int currentSubset[], int currentSize) {
    
    if (index == n) {
        // Отпечатваме текущото подмножество
        std::cout << "{ ";
        for (int i = 0; i < currentSize; ++i) {
            std::cout << currentSubset[i] << " ";
        }
        std::cout << "}" << std::endl;
        return;
    }

    // Включваме текущия елемент в подмножеството
    currentSubset[currentSize] = arr[index];
    printSubsetsHelper(arr, n, index + 1, currentSubset, currentSize + 1);

    // Не включваме текущия елемент в подмножеството
    printSubsetsHelper(arr, n, index + 1, currentSubset, currentSize);
}

void printSubsets(int arr[], int n) {
    int* currentSubset = new int[n];
    printSubsetsHelper(arr, n, 0, currentSubset, 0);
    delete[] currentSubset;
}   

const unsigned BOARD_SIZE = 9;

void printBoard(int arr[][BOARD_SIZE]) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}

bool isValidSudoku(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int current) {

     for(int i=0; i<9; i++) {

        if(board[i][col] == current) return false;

        if(board[row][i] == current) return false;

        if(board[3 * (row/3)  +  i/3][3 * (col/3)  +  i%3] == current) return false;
     }

     return true;
}

void solveSudoku(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {

    // Намерили сме решение
    if (row == BOARD_SIZE) {
        printBoard(board);
        return;
    }

    // Ако сме на края на реда -> преминаваме на следващия
    if (col == BOARD_SIZE) {
        solveSudoku(board, row + 1, 0);
        return;
    }

    // Прескачаме вече запълнените клетки
    if (board[row][col] != 0) {
        solveSudoku(board, row, col + 1);
        return;
    }

    for (int num = 1; num <= BOARD_SIZE; num++) {
        if (isValidSudoku(board, row, col, num)) {
            board[row][col] = num;
            solveSudoku(board, row, col + 1);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

void solveSudoku(int board[BOARD_SIZE][BOARD_SIZE]) {
    solveSudoku(board, 0, 0);
}

const unsigned int N = 4;

bool solveMaze(char maze[N][N], int x, int y, int pathX[], int pathY[], int &pathLength) {

    // Ако сме извън границите на лабиринта или стигнем до стена или вече посещавана клетка
    if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == '#' || maze[x][y] == 'V') {
        return false;
    }

    // Ако достигнем до изхода, добавяме в пътя и връщаме true
    if (maze[x][y] == 'E') {
        pathX[pathLength] = x;
        pathY[pathLength] = y;
        pathLength++;
        return true;
    }

    // Отбелязваме клетката като посещавана
    maze[x][y] = 'V';

    // Добавяме текущата клетка в пътя
    pathX[pathLength] = x;
    pathY[pathLength] = y;
    pathLength++;

    if (solveMaze(maze, x + 1, y, pathX, pathY, pathLength)) return true; // надолу
    if (solveMaze(maze, x - 1, y, pathX, pathY, pathLength)) return true; // нагоре
    if (solveMaze(maze, x, y + 1, pathX, pathY, pathLength)) return true; // надясно
    if (solveMaze(maze, x, y - 1, pathX, pathY, pathLength)) return true; // наляво

    // backtrack
    pathLength--;
    maze[x][y] = '.'; // Възстановяваме клетката като проходима

    return false;
}

void findAndSolveMaze(char maze[N][N]) {

    int startX = -1, startY = -1;
    int exitX = -1, exitY = -1;

    // Намираме началната и крайната позиция
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            if (maze[i][j] == 'E') {
                exitX = i;
                exitY = j;
            }
        }
    }

    // Ако не намерим началната или крайната позиция, извеждаме грешка
    if (startX == -1 || exitX == -1) {
        std::cout << "Invalid maze!" << std::endl;
        return;
    }

    // Масиви за пътя
    int pathX[N * N], pathY[N * N];
    int pathLength = 0;

    if (solveMaze(maze, startX, startY, pathX, pathY, pathLength)) {
        // Отпечатваме пътя
        for (int i = 0; i < pathLength; ++i) {
            std::cout << "(" << pathX[i] << "," << pathY[i] << ")";
            if (i != pathLength - 1) std::cout << " -> ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path!" << std::endl;
    }
}



int main() {

    int arr[] = {1, 2, 3};

    std::cout << "Factorial of 5 is " << factorial(5) << std::endl << std::endl;
    std::cout << "The 8th fibonacci number is " << fibonacci(8) << std::endl << std::endl;
    std::cout << "2 to the power of 10 is " << pow(2, 10) << std::endl << std::endl;
    std::cout << "2 to the power of 13 is " << fastPow(2, 13) << std::endl << std::endl;
    std::cout << "Does {1, 2, 3} contain 4? " << std::boolalpha << contains(arr, 3, 4) << std::endl << std::endl;
    std::cout << "Does {1, 2, 3} contain 3? " << std::boolalpha << contains(arr, 3, 3) << std::endl << std::endl;
    std::cout << "The product of {1, 2, 3} is " << findProduct(arr, 3) << std::endl << std::endl;
    std::cout << "The product of {1, 2, 3} is " << findProduct2(arr, 3) << std::endl << std::endl;
    std::cout << "The reverse of \"James Gosling\" is ";
    printReversedString("James Gosling"); 
    std::cout << std::endl << std::endl;
    std::cout << "Is \"(()\" valid exppresion? " << std::boolalpha << isValidExpression("(()") << std::endl << std::endl;
    std::cout << "Is \"(())\" valid exppresion? " << std::boolalpha << isValidExpression("(())") << std::endl << std::endl;
    std::cout << "Is \"(()))\" valid exppresion? " << std::boolalpha << isValidExpression("())(") << std::endl << std::endl;
    std::cout << "All subsets of {1, 2, 3} are: " << std::endl;
    printSubsets(arr, 3);
    std::cout << std::endl;
    
    int board[BOARD_SIZE][BOARD_SIZE] = { 
        {5, 3, 0, 0, 7, 0, 0, 0, 0}, 
        {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
        {0, 9, 8, 0, 0, 0, 0, 6, 0}, 
        {8, 0, 0, 0, 6, 0, 0, 0, 3}, 
        {4, 0, 0, 8, 0, 3, 0, 0, 1}, 
        {7, 0, 0, 0, 2, 0, 0, 0, 6}, 
        {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
        {0, 0, 0, 4, 1, 9, 0, 0, 5}, 
        {0, 0, 0, 0, 8, 0, 0, 7, 9} 
    };

    std::cout << "Solved sudoku: " << std::endl;
    solveSudoku(board);

    char maze[N][N] = { 
        {'S', '.', '#', '.'}, 
        {'.', '.', '#', '.'}, 
        {'#', '.', '.', '.'}, 
        {'.', '#', '#', 'E'} 
    };

    std::cout << "Solution to the maze: " << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
    
    std::cout << std::endl;
    findAndSolveMaze(maze);

    return 0;
}
