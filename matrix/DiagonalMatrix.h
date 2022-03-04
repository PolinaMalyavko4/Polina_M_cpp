//
// Created by Заурбек Тедеев on 07.12.2021.
//

#ifndef MATRIX_DIAGONALMATRIX_H
#define MATRIX_DIAGONALMATRIX_H
#include "matrix.h"

class DiagonalMatrix : public Matrix{
public:
    explicit DiagonalMatrix(size_t n, bool is_fill_random);

    void fill_random() override;
};


#endif //MATRIX_DIAGONALMATRIX_H
