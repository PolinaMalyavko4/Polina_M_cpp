//
// Created by Заурбек Тедеев on 07.12.2021.
//

#ifndef MATRIX_SINGLEMATRIX_H
#define MATRIX_SINGLEMATRIX_H
#include "matrix.h"

class SingleMatrix : public Matrix {
public:
    explicit SingleMatrix(size_t n);

    void resize(size_t new_n);
};


#endif //MATRIX_SINGLEMATRIX_H
