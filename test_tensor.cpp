#include <iostream>
#include "tensor.h"
#include <random>


int main() {
    std::cout << "\n\nTesting tensor.h ..." << std::endl;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 9);
    std::uniform_real_distribution<> dim(1, 5);

    int row = int(dim(gen));
    int col = int(dim(gen));

    int err = 0;

    Tensor t(row, col);

    t.print();

    std::cout << "\n\nFilling tensor with random values between 0 and 9 ..." << std::endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            err = t.setData(i, j, int(dis(gen)));
            if(0 != err) {
                std::cout << "Error setting data at (" << i << ", " << j << ")" << std::endl;
                return err;
            }
        }
    }

    std::cout << "Tensor T1:\n" << std::endl;
    t.print();

    std::cout << "\n\nTransposing tensor ..." << std::endl;
    Tensor* t_transposed = t.transpose();

    std::cout << "Transposed Tensor T1:\n";
    t_transposed->print();

    std::cout << "\n\nTesting addition operator ..." << std::endl;
    Tensor t2(row, col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            err = t2.setData(i, j, int(dis(gen)));
            if(0 != err) {
                std::cout << "Error setting data at (" << i << ", " << j << ")" << std::endl;
                return err;
            }
        }
    }

    std::cout << "\n\nTensor T2:\n";
    t2.print();

    Tensor t3 = t + t2;

    std::cout << "\n\nTensor T3 = T1 + T2:\n";
    t3.print();

    int t4_row = col;
    int t4_col = int(dim(gen));
    Tensor t4_multiply(t4_row, t4_col);

    std::cout << "\n\nTesting multiplication operator ..." << std::endl;

    for (int i = 0; i < t4_row; i++) {
        for (int j = 0; j < t4_col; j++) {
            err = t4_multiply.setData(i, j, int(dis(gen)));
            if(0 != err) {
                std::cout << "Error setting data at (" << i << ", " << j << ")" << std::endl;
                return err;
            }
        }
    }

    Tensor t5 = t * t4_multiply;

    t5.print();

    return 0;
}