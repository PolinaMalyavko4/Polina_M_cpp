//
// Created by Заурбек Тедеев on 10.12.2021.
//

#ifndef MATRIX_TRIANGLELOWMATRIX_H
#define MATRIX_TRIANGLELOWMATRIX_H

#include "matrix.h"

class TriangleLowMatrix: public Matrix {
public:
    TriangleLowMatrix(size_t n, bool is_fill_random);

    void fill_random() override;
};


#endif //MATRIX_TRIANGLELOWMATRIX_H
