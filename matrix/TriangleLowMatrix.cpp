//
// Created by Заурбек Тедеев on 10.12.2021.
//

#include "TriangleLowMatrix.h"

TriangleLowMatrix::TriangleLowMatrix(size_t n, bool is_fill_random): Matrix(n, n, false) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            matrix[i][j] = 1;
        }
    }

    if (is_fill_random){
        fill_random();
    }
}

void TriangleLowMatrix::fill_random() {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            matrix[i][j] = 1 + random() % 100;
        }
    }
}
