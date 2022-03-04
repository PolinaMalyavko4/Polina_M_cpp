//
// Created by Заурбек Тедеев on 07.12.2021.
//

#include "matrix.h"

Matrix::Matrix(size_t n, size_t m, bool is_fill_random){
    this->n = n;
    this->m = m;

    matrix.assign(n, vector<double>(m));

    if(is_fill_random){
        fill_random();
    }
}

vector<double>& Matrix::operator[](size_t index) {
    return matrix[index];
}

ostream& operator<< (ostream& out, Matrix& mtr){
    for(int i = 0; i < mtr.n; i++){
        for(int j = 0; j < mtr.m; j++){
            out << mtr[i][j] << "\t";
        }
        out << "\n";
    }

    return out;
}

ostream& operator<< (ostream& out, Matrix* mtr){
    for(int i = 0; i < mtr->n; i++){
        for(int j = 0; j < mtr->m; j++){
            out << mtr->matrix[i][j] << "\t";
        }
        out << "\n";
    }

    return out;
}

void Matrix::resize(size_t n, size_t m, bool is_fill_random) {
    matrix.clear();

    this->n = n;
    this->m = m;

    matrix.assign(n, vector<double>(m));

    if(is_fill_random){
        fill_random();
    }
}

void Matrix::fill_random() {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = 1 + random() % 100;
        }
    }
}

Matrix &Matrix::do_operation(Matrix &left, Matrix &right, int (*f)(int, int)) {
    if (!left.is_equals_size(right)){
        throw length_error("Matrices must be of the same size");
    }

    auto* result = new Matrix(left.rows(), left.columns(), false);
    for(int i = 0; i < left.rows(); i++){
        for(int j = 0; j < left.columns(); j++){
            result->matrix[i][j] = f(left[i][j], right[i][j]);
        }
    }

    return *result;
}

size_t Matrix::rows() const {
    return n;
}

size_t Matrix::columns() const {
    return m;
}

bool Matrix::is_equals_size(Matrix& other) const{
    return this->rows() == other.rows() && this->columns() == other.columns();
}

Matrix &operator+(Matrix &left, Matrix &right) {
    return Matrix::do_operation(left, right, [](int a, int b){
        return a + b;
    });
}

Matrix &operator-(Matrix &left, Matrix &right) {
    return Matrix::do_operation(left, right, [](int a, int b){
        return a - b;
    });
}

Matrix &Matrix::adamar(Matrix&left, Matrix &right) {
    return Matrix::do_operation(left, right, [](int a, int b){
        return a * b;
    });
}

Matrix &operator*(Matrix &left, int right) {
    auto* result = new Matrix(left.rows(), left.columns(), false);
    for(int i = 0; i < left.rows(); i++){
        for(int j = 0; j < left.columns(); j++){
            result->matrix[i][j] = left[i][j] * right;
        }
    }

    return *result;
}

Matrix &operator* (int left, Matrix& right){
    return right * left;
}

Matrix &operator*(Matrix &left, Matrix &right) {
    if (left.columns() != right.rows()){
        throw length_error("Columns of the first matrix must be equals to rows of the second matrix");
    }

    auto* result = new Matrix(left.rows(), right.columns(), false);

    for(int i = 0; i < left.rows(); i++){
        for(int j = 0; j < right.columns(); j++){
            for(int k = 0; k < left.columns(); k++){
                result->matrix[i][j] += left[i][k] * right[k][j];
            }
        }
    }

    return *result;
}

Matrix& Matrix::remove_row(size_t index) const{
    auto* result = new Matrix(this->rows() - 1, this->columns(), false);
    for (int i = 0; i < index; i++){
        for(int j = 0; j < this->columns(); j++){
            result->matrix[i][j] = this->matrix[i][j];
        }
    }

    for(size_t i = index + 1; i < this->rows(); i++){
        for(int j = 0; j < this->columns(); j++){
            result->matrix[i - 1][j] = this->matrix[i][j];
        }
    }

    return *result;
}

Matrix& Matrix::remove_column(size_t index) const {
    auto* result = new Matrix(this->rows(), this->columns() - 1, false);
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < index; j++){
            result->matrix[i][j] = this->matrix[i][j];
        }

        for(size_t j = index + 1; j < this->columns(); j++){
            result->matrix[i][j - 1] = this->matrix[i][j];
        }
    }

    return *result;
}

double Matrix::determinant() const{
    if (this->columns() != this->rows()){
        throw length_error("Matrix's count of rows and columns must be equals");
    }

    int k = 1;
    size_t side = this->rows();
    if (side < 1){
        throw length_error("Length error");
    }

    int det = 0;
    if (side == 1){
        det = matrix[0][0];
        return det;
    }
    if (side == 2) {
        det = matrix[0][0] * matrix[1][1] - (matrix[1][0] * matrix[0][1]);
        return det;
    }
    if (side > 2) {
        for (int i = 0; i < side; i++) {

            Matrix temp = this->remove_row(i).remove_column(0);
            det = det + k * matrix[i][0] * temp.determinant();
            k = -k;
        }
    }

    return det;
}

double Matrix::max_norm(size_t row) const {
    int max = this->matrix[row][0];
    for(int i = 0; i < this->columns(); i++){
        if (max < this->matrix[row][i]){
            max = this->matrix[row][i];
        }
    }

    return max;
}

double Matrix::euclid_norm(){
    Matrix c = Matrix::copy(*this);
    if (c.columns() == 1){
        c = c.transposition();
    }
    double sum_sq = 0;
    for(int i = 0; i < c.columns(); i++){
        sum_sq += pow(c.matrix[0][i], 2);
    }
    return sqrt(sum_sq);


}

double Matrix::frobenius_norm() const {
    double sum_sq = 0;
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->columns(); j++){
            sum_sq += pow(this->matrix[i][j], 2);
        }
    }

    return sqrt(sum_sq);
}

Matrix &Matrix::transposition() const {
    auto* result = new Matrix(this->columns(), this->rows(), false);
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->columns(); j++){
            result->matrix[j][i] = this->matrix[i][j];
        }
    }

    return *result;
}

Matrix &Matrix::reverse_matrix() const {
    auto* result = new Matrix(this->rows(), this->columns(), false);
    double det = this->determinant();
    if (det == 0){
        throw runtime_error("Determinant must be not equals to zero");
    }
    for (int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->columns(); j++){
            Matrix temp = this->remove_row(i).remove_column(j);
            result->matrix[i][j] = pow(-1.0, i + j + 2) * (double)temp.determinant() / det;
        }
    }

    return result->transposition();
}

Matrix &Matrix::copy(Matrix& mtr) {
    auto* result = new Matrix(mtr.rows(), mtr.columns(), false);
    for(int i = 0; i < mtr.rows(); i++){
        for(int j = 0; j < mtr.columns(); j++){
            result->matrix[i][j] = mtr.matrix[i][j];
        }
    }

    return *result;
}

double Matrix::determinant_gaus() {
    if (this->columns() != this->rows()){
        throw length_error("Matrix's count of rows and columns must be equals");
    }
    Matrix B = Matrix::copy((*this));
    //приведение матрицы к верхнетреугольному виду
    for(int step = 0; step < n - 1; step++)
        for(int row = step + 1; row < n; row++)
        {
            double coeff = -B[row][step] / B[step][step]; //метод Гаусса
            for(int col = step; col < n; col++)
                B[row][col] += B[step][col] * coeff;
        }
    //Рассчитать определитель как произведение элементов главной диагонали
    double Det = 1;
    for(int i = 0; i < n; i++)
        Det *= B[i][i];
    //Очистить память
    return Det;
}

double Matrix::scalar(Matrix &left, Matrix &right) {
    if (left.rows() == 1 && right.columns() == 1 &&
        left.columns() == right.rows()){
        Matrix r = left * right;
        return r[0][0];
    }
    else if (left.rows() == 1 && right.rows() == 1 &&
            left.columns() == right.columns()){

        Matrix r = left * right.transposition();
        return r[0][0];
    }
    else if (left.columns() == 1 && right.columns() == 1 &&
             left.rows() == right.rows()) {
        Matrix r = left.transposition() * right;
        return r[0][0];
    }
    else if (left.columns() == 1 && right.rows() == 1 &&
             left.rows() == right.columns()){
        Matrix r = left.transposition() * right.transposition();
        return r[0][0];
    }
    else{
        throw runtime_error("Vectors are invalid");
    }

}

double Matrix::cos_vector(Matrix &left, Matrix &right) {
    return acos(Matrix::scalar(left, right) / (left.euclid_norm() * right.euclid_norm()));
}

istream& operator>> (istream& in, Matrix& mtr){
    for(int i = 0; i < mtr.rows(); i++){
        for(int j = 0; j < mtr.columns(); j++){
            in >> mtr.matrix[i][j];
        }
    }

    return in;
}

istream& operator>> (istream& in, Matrix* mtr) {
    for(int i = 0; i < mtr->rows(); i++){
        for(int j = 0; j < mtr->columns(); j++){
            in >> mtr->matrix[i][j];
        }
    }

    return in;
}
