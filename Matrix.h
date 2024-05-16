#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    unsigned int m;
    unsigned int n;

public:
    Matrix(unsigned int rows, unsigned int cols);
    ~Matrix();

    void fillRandom();

    std::vector<int>& operator[](unsigned int index);
    const std::vector<int>& operator[](unsigned int index) const;

    Matrix& operator+=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;

    Matrix& operator-=(const Matrix& other);
    Matrix operator-(const Matrix& other) const;

    Matrix operator*(const Matrix& other) const;

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

#endif // MATRIX_H
