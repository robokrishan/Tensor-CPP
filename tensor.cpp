#include "tensor.h"


Tensor::Tensor(int rows, int cols) : rows(rows), cols(cols) {
    data = new float* [rows];
    for(int i = 0; i < rows; i++) {
        data[i] = new float[cols];
        for(int j = 0; j < cols; j++) {
            data[i][j] = 0.0;
        }
    }
}

Tensor::~Tensor() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void Tensor::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Tensor::setData(int row, int col, float value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row][col] = value;
        return 0;
    }

    return -1;
}

Tensor* Tensor::transpose() const {
    Tensor* transposed = new Tensor(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed->data[j][i] = data[i][j];
        }
    }
    return transposed;
}

Tensor Tensor::operator+(const Tensor& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Tensor dimensions must match for addition.");
    }

    Tensor result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Tensor Tensor::operator-(const Tensor& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Tensor dimensions must match for subtraction.");
    }

    Tensor result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Tensor Tensor::operator*(const Tensor& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Tensor dimensions are not compatible for multiplication.");
    }

    Tensor result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}   

Tensor Tensor::operator*(float scalar) const {
    Tensor result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Tensor& Tensor::operator=(const Tensor& other) {
    if (this != &other) {
        if (rows != other.rows || cols != other.cols) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;

            rows = other.rows;
            cols = other.cols;
            data = new float* [rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new float[cols];
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}