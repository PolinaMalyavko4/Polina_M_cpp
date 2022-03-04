#include <iostream>
#include "matrix.h"
#include "SingleMatrix.h"
#include "DiagonalMatrix.h"
#include "TriangleHighMatrix.h"
#include "TriangleLowMatrix.h"
#include <fstream>
using namespace std;

int main() {
    srand(time(NULL));

    size_t n = 3;
    size_t m = 3;
    //Matrix* mtr = new Matrix(n, m, true);
    Matrix mtr(n, m, true);

    mtr[0][0] = 1;
    mtr[0][1] = 7;
    mtr[0][2] = 3;

    mtr[1][0] = 4;
    mtr[1][1] = 8;
    mtr[1][2] = 6;

    mtr[2][0] = 5;
    mtr[2][1] = 3;
    mtr[2][2] = 4;
    cout << mtr << endl;

//    Matrix t1 = mtr.remove_column(0);
//    cout << t1 << endl;
//
//    Matrix t2 = t1.remove_row(3);
//    cout << t2 << endl;
//
//    Matrix t3 = mtr.remove_column(0).remove_row(3);
//    cout << t3 << endl;

    cout << mtr.determinant() << endl;
    cout << mtr.determinant_gaus() << endl;
    Matrix t = mtr.transposition();
    cout << t << endl;

    Matrix r = mtr.reverse_matrix();
    cout << r << endl;

    Matrix vec1(1, 3, true);
    Matrix vec2(3, 1, true);

    cout << vec1 << endl << vec2 << endl << Matrix::scalar(vec1, vec2) << endl;
    cout << Matrix::cos_vector(vec1, vec2) << endl;
//    //SingleMatrix* smtr = new SingleMatrix(n);
//    SingleMatrix smtr(n);
//    cout << smtr << endl;
//
//    smtr.resize(10);
//    cout << smtr << endl;
//
//    DiagonalMatrix dmtr(n, true);
//    cout << dmtr << endl;
//
//    TriangleHighMatrix thmtr(n, true);
//    cout << thmtr << endl;
//
//    TriangleLowMatrix tlmtr(n, true);
//    cout << tlmtr << endl;
//
//    Matrix t1 = thmtr + tlmtr;
//    cout << t1 << endl;
//
//    Matrix t2 = thmtr - tlmtr;
//    cout << t2 << endl;
//
//    Matrix t3 = Matrix::adamar(thmtr, t2);
//    cout << t3 << endl;
//
//    Matrix t4 = 2 * t3;
//    cout << t4 << endl;
//
//    Matrix t5(2, 3, true);
//    Matrix t6(3, 2, true);
//    Matrix t7 = t5 * t6;
//    cout << t5 << endl << t6;
//    cout << t7 << endl;

    ifstream in("data.txt");
    Matrix o(32, 12, false);
    in >> o;

    cout << o;



    return 0;
}
