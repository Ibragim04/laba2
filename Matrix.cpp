#include "Matrix.h"
#include <cstdlib> // для функции rand()

Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
    data.resize(m, std::vector<int>(n));
}

Matrix::~Matrix() {}

void Matrix::fillRandom() {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] = rand() % 10; // случайное число от 0 до 9
        }
    }
}

std::vector<int>& Matrix::operator[](unsigned int index) {
    return data[index];
}

const std::vector<int>& Matrix::operator[](unsigned int index) const {
    return data[index];
}

Matrix& Matrix::operator+=(const Matrix& other) {
    // Проверка на соответствие размеров матриц
    if (m != other.m || n != other.n) {
        // Обработка ошибки, например, выбрасывание исключения
    }

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(m, n);
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    // Проверка на соответствие размеров матриц
    if (m != other.m || n != other.n) {
        // Обработка ошибки, например, выбрасывание исключения
    }

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(m, n);
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (n != other.m) {
        // Обработка ошибки, например, выбрасывание исключения
    }

    Matrix result(m, other.n);
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < other.n; ++j) {
            for (unsigned int k = 0; k < n; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    if (m != other.m || n != other.n) {
        return false;
    }
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; ++i) {
        for (unsigned int j = 0; j < matrix.n; ++j) {
            os << matrix.data[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}
