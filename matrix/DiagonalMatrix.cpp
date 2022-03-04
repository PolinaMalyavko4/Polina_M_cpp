//
// Created by Заурбек Тедеев on 07.12.2021.
//

#include "DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(size_t n, bool is_fill_random): Matrix(n, n, false) {
    for(int i = 0; i < n; i++){
        matrix[i][i] = 1;
    }

    if(is_fill_random){
        fill_random();
    }
}

void DiagonalMatrix::fill_random(){
    for(int i = 0; i < n; i++){
        matrix[i][i] = 1 + random() % 100;
    }
}

