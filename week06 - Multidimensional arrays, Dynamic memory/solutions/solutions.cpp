#include <iostream>

//Task01
int sumOfMatrixElements(int** matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

//Task02
void printMatrixElements(int** matrix, int size) {

    std::cout << "Main Diagonal: ";
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i][i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Second diagonal: ";
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i][size - i - 1] << " ";
    }
    std::cout << std::endl;

    std::cout << "Above main diagonal: ";
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Under main diagonal: ";
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

//Task 03
int** addMatrices(int** A, int** B, int rows, int cols) {
    int** result = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        result[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Функция за изваждане на матрици
int** subtractMatrices(int** A, int** B, int rows, int cols) {
    int** result = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        result[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// Функция за умножение на две матрици
int** multiplyMatrices(int** A, int rowsA, int colsA, int** B, int rowsB, int colsB) {
    if (colsA != rowsB) {
        std::cout << "Cannot multiply!";
        return nullptr;
    }

    int** result = new int* [rowsA];
    for (int i = 0; i < rowsA; ++i) {
        result[i] = new int[colsB];
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            //Умножение по правилото ред по стълб
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

//Task 04
void transpose(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = tmp;
        }
    }
}

//Task 05
void spiralOrder(int** matrix, int row, int col) {
    int count = 0;
    int total = row * col;

    //index initialization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total) {
        //printing starting row
        for (int index = startingCol; count < total && index <= endingCol; index++) {
            std::cout << matrix[startingRow][index] << " ";
            count++;
        }
        startingRow++;

        //printing ending column
        for (int index = startingRow; count < total && index <= endingRow; index++) {
            std::cout << matrix[index][endingCol] << " ";
            count++;
        }
        endingCol--;

        //printing ending row
        for (int index = endingCol; count < total && index >= startingCol; index--) {
            std::cout << matrix[endingRow][index] << " ";
            count++;
        }
        endingRow--;

        //printing starting column
        for (int index = endingRow; count < total && index >= startingRow; index--) {
            std::cout << matrix[index][startingCol] << " ";
            count++;
        }
        startingCol++;
    }

    std::cout << std::endl;
}

//Task 06
int** order(int* numbers, int size, int k) {
    int numRows = size / k;
    int** mat = new int* [numRows];

    // overallCounter ще ни казва кой елемент от numbers трябва да сложим в matrix[i][j]
    // Можеше да се мине и без тази променлива като в цикъла щеше да бъде numbers[i * k + j]
    int overallCounter = 0;
    for (int i = 0; i < numRows; i++) {
        mat[i] = new int[k];
        for (int j = 0; j < k; j++) {
            mat[i][j] = numbers[overallCounter++];
        }
    }

    return mat;
}

//Task 07
int** groupBy(int* numbers, int size, int p) {
    int** remainderGroups = new int* [p];

    // Циклим по редовете, като техните индекси съвпадат със съответния остатък при деление на p
    for (int remainder = 0; remainder < p; remainder++) {
        
        int countCandidates = 0;
        for (int i = 0; i < size; i++) {
            if (numbers[i] % p == remainder) {
                countCandidates++;
            }
        }

        remainderGroups[remainder] = new int[countCandidates];

        int currentCol = 0;
        for (int i = 0; i < size; i++) {
            if (numbers[i] % p == remainder) {
                remainderGroups[remainder][currentCol++] = numbers[i];
            }
        }
    }
    return remainderGroups;
}

//Task 08
void reflect(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = tmp;
        }
    }
}

void rotate(int** matrix, int n) {
    transpose(matrix, n);
    reflect(matrix, n);
}

//Task 09
void deleteAt(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index\n";
        return;
    }

    // Създаване на нов масив с намален размер
    int* newArr = new int[size - 1];

    // Копиране на елементите преди и след изтрития
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            newArr[j++] = arr[i];
        }
    }

    // Освобождаване на паметта на стария масив и насочване към новия
    delete[] arr;
    arr = newArr;
    --size;
}

void insertAt(int*& arr, int& size, int index, int val) {
    if (index < 0 || index > size) {
        std::cout << "Invalid index\n";
        return;
    }

    // Създаване на нов масив с увеличен размер
    int* newArr = new int[size + 1];

    // Копиране на елементите и вмъкване на новия
    for (int i = 0, j = 0; i < size + 1; ++i) {
        if (i == index) {
            newArr[i] = val;
        }
        else {
            newArr[i] = arr[j++];
        }
    }

    // Освобождаване на паметта на стария масив и насочване към новия
    delete[] arr;
    arr = newArr;
    ++size;
}

//Task 10
void deleteColumn(int**& matrix, int rows, int& cols, int k) {
    if (k < 0 || k >= cols) {
        std::cout << "Invalid column index\n";
        return;
    }

    // За всяки ред намаляме размера на масива и копираме елементите
    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols - 1];

        for (int j = 0, colIdx = 0; j < cols; ++j) {
            if (j != k) {
                newRow[colIdx++] = matrix[i][j];
            }
        }

        delete[] matrix[i];  // Освобождаваме стария ред
        matrix[i] = newRow;   // Насочваме към новия ред
    }

    // Намаляме броя на колоните
    --cols;
}

void printMatrix(int**, int, int);
void freeMatrix(int**, int);

int main() {

    int rows = 4, cols = 4;
    int** matrix1 = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix1[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix1[i][j] = (i + 1) + j;
        }
    }

    int** matrix2 = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix2[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix2[i][j] = (i * cols) + j + 1;
        }
    }

    std::cout << "Original matrix: " << std::endl;
    printMatrix(matrix2, rows, cols);

    std::cout << "Spiral order: " << std::endl;
    spiralOrder(matrix2, rows, cols);

    std::cout << "Transposed: " << std::endl;
    transpose(matrix2, rows);
    printMatrix(matrix2, rows, cols);

    std::cout << "Rotated: " << std::endl;
    rotate(matrix2, rows);
    printMatrix(matrix2, rows, cols);

    std::cout << "Delete first column: " << std::endl;
    deleteColumn(matrix2, rows, cols, 0);
    printMatrix(matrix2, rows, cols);


    freeMatrix(matrix1, rows);
    freeMatrix(matrix2, rows);
}

void freeMatrix(int** matrix, int rows) {

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int** matrix, int rows, int cols) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
