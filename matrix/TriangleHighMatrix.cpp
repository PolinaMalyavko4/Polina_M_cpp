//
// Created by Заурбек Тедеев on 10.12.2021.
//

#include "TriangleHighMatrix.h"

TriangleHighMatrix::TriangleHighMatrix(size_t n, bool is_fill_random) : Matrix(n, n, false) {
    for(int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            matrix[i][j] = 1;
        }
    }

    if (is_fill_random){
        fill_random();
    }
}

void TriangleHighMatrix::fill_random() {
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            matrix[i][j] = 1 + random() % 100;
        }
    }
}
