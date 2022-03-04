//
// Created by Заурбек Тедеев on 07.12.2021.
//

#include "SingleMatrix.h"

SingleMatrix::SingleMatrix(size_t n): Matrix(n, n, false){
    for(int i = 0; i < n; i++){
        matrix[i][i] = 1;
    }
}

void SingleMatrix::resize(size_t new_n) {
    Matrix::resize(new_n, new_n, false);
    for(int i = 0; i < n; i++){
        matrix[i][i] = 1;
    }
}
