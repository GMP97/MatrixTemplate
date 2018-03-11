#include <iostream>
#include "MatrixTemplate.h"

int main() {

    MatrixTemplate<float> A(3, 2);
    A.setValue(1, 1, 1.32);
    A.setValue(1, 2, 2);
    A.setValue(2, 1, 1.15);
    A.setValue(2, 2, 3.47);
    A.setValue(3, 1, 2.85);
    A.setValue(3, 2, 1);
    A.print();
    MatrixTemplate<float> B(2, 3);
    B.setValue(1, 1, 2.89);
    B.setValue(1, 2, 0.58);
    B.setValue(1, 3, 5);
    B.setValue(2, 1, 1.25);
    B.setValue(2, 2, 1.55);
    B.setValue(2, 3, 3);
    B.print();
    MatrixTemplate<float> C = A * B;
    C.print();
    MatrixTemplate<float> D = C.transpose();
    D.print();
    MatrixTemplate<float> Dcl = D.selectColumn(1);
    Dcl.print();
    MatrixTemplate<float> Drw = D.selectRow(3);
    Drw.print();
}