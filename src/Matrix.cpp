#include <iostream>
#include "Matrix.h"

Matrix &Matrix::operator=(double value) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            table[i][j] = value;
        }
    }
    return *this;
}

void Matrix::print() {
    for (int i = 0; i < this->height; ++i) {
        std::cout << "|";
        for (int j = 0; j < this->width; ++j) {
            std::cout << " " << this->table[i][j] << " ";
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}

Matrix &Matrix::operator*(double value) {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            this->table[i][j] *= value;
        }
    }
    return *this;
}

Matrix &Matrix::operator+(double value) {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            this->table[i][j] += value;
        }
    }
    return *this;
}

Matrix &Matrix::operator+(Matrix other) {
    if (!this->canAdd(other)) {
        throw std::runtime_error("Cannot add this matrices!");
    }

    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            this->table[i][j] += other.get(i, j);
        }
    }

    return *this;
}

Matrix &Matrix::operator*(Matrix other) {
    if (!this->canMultiply(other)) {
        throw std::runtime_error("Cannot multiply this matrices!");
    }

    Matrix product(other.getColumnSize(), this->getRowSize());
    product = 0;
    for (int i = 0; i < this->getRowSize(); ++i) {
        for (int j = 0; j < other.getColumnSize(); ++j) {
            double sum = 0;
            for (int k = 0; k < this->getColumnSize(); ++k) {
                double tmp = table[i][k] * other.get(k, j);
                sum += tmp;
            }
            product.set(i, j, sum);
        }
    }
    return product;
}



