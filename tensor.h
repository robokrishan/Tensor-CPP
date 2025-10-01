#include <iostream>


class Tensor {
    public:
        Tensor(int rows, int cols);
        ~Tensor();
        void print() const;
        int setData(int row, int col, float value);
        Tensor* transpose() const;

        // Overload operators
        Tensor operator+(const Tensor& other) const;
        Tensor operator-(const Tensor& other) const;
        Tensor operator*(const Tensor& other) const;
        Tensor operator*(float scalar) const;
        Tensor& operator=(const Tensor& other);
    private:
        int rows;
        int cols;
        float** data;
};