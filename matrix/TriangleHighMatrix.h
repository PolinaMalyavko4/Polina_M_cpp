//
// Created by Заурбек Тедеев on 10.12.2021.
//

#ifndef MATRIX_TRIANGLEHIGHMATRIX_H
#define MATRIX_TRIANGLEHIGHMATRIX_H
#include "matrix.h"

class TriangleHighMatrix: public Matrix {
public:
    TriangleHighMatrix(size_t n, bool is_fill_random);

    void fill_random() override;
};


#endif //MATRIX_TRIANGLEHIGHMATRIX_H
