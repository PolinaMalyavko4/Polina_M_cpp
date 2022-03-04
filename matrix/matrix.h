//
// Created by Заурбек Тедеев on 07.12.2021.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//template<typename T>
class Matrix {
private:
    static Matrix& do_operation(Matrix& left, Matrix& right, int (*f)(int, int));
protected:
    vector<vector<double>> matrix;
    size_t n, m;
public:
    Matrix(size_t n, size_t m, bool is_fill_random);
    vector<double>& operator[] (size_t index);

    virtual void resize(size_t n, size_t m, bool is_fill_random);
    virtual void fill_random();

    size_t rows() const;
    size_t columns() const;

    bool is_equals_size(Matrix& other) const;

    Matrix& remove_row(size_t index) const;
    Matrix& remove_column(size_t index) const;


    double determinant() const;
    double determinant_gaus();
    double max_norm(size_t row = 0) const;
    double euclid_norm();
    double frobenius_norm() const;
    Matrix& transposition() const;

    Matrix& reverse_matrix() const;

    static Matrix& adamar(Matrix& left, Matrix& right);
    static Matrix& copy(Matrix& mtr);
    static double scalar(Matrix& left, Matrix& right);
    static double cos_vector(Matrix& left, Matrix& right);

    friend ostream& operator<< (ostream& out, Matrix& mtr);
    friend ostream& operator<< (ostream& out, Matrix* mtr);
    friend istream& operator>> (istream& in, Matrix& mtr);
    friend istream& operator>> (istream& in, Matrix* mtr);

    friend Matrix& operator+ (Matrix& left, Matrix& right);
    friend Matrix& operator- (Matrix& left, Matrix& right);
    friend Matrix& operator* (Matrix& left, int right);
    friend Matrix& operator* (int left, Matrix& right);
    friend Matrix& operator* (Matrix& left, Matrix& right);

};


#endif //MATRIX_MATRIX_H
