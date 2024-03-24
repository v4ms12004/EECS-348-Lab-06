#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 10;

void readMatrixFromFile(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        exit(1);
    }
    file >> size;
    if (size <= 0 || size > MAX_SIZE) {
        std::cerr << "Invalid matrix size." << std::endl;
        exit(1);
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (!(file >> matrix1[i][j])) {
                std::cerr << "Error reading matrix data." << std::endl;
                exit(1);
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (!(file >> matrix2[i][j])) {
                std::cerr << "Error reading matrix data." << std::endl;
                exit(1);
            }
        }
    }
    file.close();
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int size, int row, int col, int newValue) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column." << std::endl;
    }
}

int getMaxValue(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int transposed[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    printMatrix(transposed, size);
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    readMatrixFromFile(matrix1, matrix2, size, "matrix_input.txt");

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, size);

    std::cout << "Matrix 2:" << std::endl;
    printMatrix(matrix2, size);

    addMatrices(matrix1, matrix2, result, size);
    std::cout << "Sum of matrices:" << std::endl;
    printMatrix(result, size);

    subtractMatrices(matrix1, matrix2, result, size);
    std::cout << "Difference of matrices:" << std::endl;
    printMatrix(result, size);

    multiplyMatrices(matrix1, matrix2, result, size);
    std::cout << "Product of matrices:" << std::endl;
    printMatrix(result, size);

    updateElement(matrix1, size, 0, 0, 100);
    std::cout << "Matrix 1 after updating element (0, 0) with 100:" << std::endl;
    printMatrix(matrix1, size);

    std::cout << "Max value in Matrix 1 after the update: " << getMaxValue(matrix1, size) << std::endl;

    std::cout << "Transpose of Matrix 1:" << std::endl;
    transposeMatrix(matrix1, size);

    return 0;
}
