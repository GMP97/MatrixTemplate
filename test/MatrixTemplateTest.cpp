//
// Created by gmp on 10/03/18.
//

#include "gtest/gtest.h"
#include "../MatrixTemplate.h"

TEST(MatrixTemplate, ConstructorTest) {
    MatrixTemplate<int> A(3,5);
    ASSERT_EQ(3, A.getRows());
    ASSERT_EQ(5, A.getColumns());
    ASSERT_EQ(A.getValue(1,1),0);
}

TEST(MatrixTemplate, CopyConstTest){
    MatrixTemplate<float> A(2,4);
    A.setValue(1,1, 1.2);
    A.setValue(1,2, 2.3);
    A.setValue(1,3, 3);
    A.setValue(2,1, 3.5);
    MatrixTemplate<float> B(A);
    ASSERT_TRUE(A==B);
}

TEST(MatrixTemplate, EqualOperatorTest){
    MatrixTemplate<int> A(2,3);
    A.setValue(1,1,3);
    A.setValue(1,2,2);
    A.setValue(2,2,5);
    MatrixTemplate<int> B=A;
    ASSERT_TRUE(A==B);
}

TEST(MatrixTemplate, EqualTest){
    MatrixTemplate<long int> A(2,5);
    A.setValue(1,1,35);
    A.setValue(1,2,75);
    A.setValue(2,2,66);
    MatrixTemplate<long int> B (A);
    ASSERT_TRUE(A==B);
    B.setValue(1,1,50);
    ASSERT_FALSE(A==B);
}

TEST(MatrixTemplate, NotEqualTest){
    MatrixTemplate<long int> A(2,5);
    A.setValue(1,1,35);
    A.setValue(1,2,75);
    A.setValue(2,2,66);
    MatrixTemplate<long int> B (A);
    ASSERT_FALSE(A!=B);
    B.setValue(1,1,50);
    ASSERT_TRUE(A!=B);
}

TEST(MatrixTemplate, PlusEqualOperatorTest){
    MatrixTemplate<float> A(2,2);
    A.setValue(1,1,3.5);
    A.setValue(1,2,7.5);
    A.setValue(2,1,8.3);
    A.setValue(2,2,6.6);
    MatrixTemplate<float> B(2,2);
    B.setValue(1,1,3.4);
    B.setValue(2,2,4.7);
    MatrixTemplate<float> C(2,2);
    C.setValue(1,1,6.9);
    C.setValue(1,2,7.5);
    C.setValue(2,1,8.3);
    C.setValue(2,2,11.3);
    A+=B;
    ASSERT_FLOAT_EQ(A.getValue(1,1),C.getValue(1,1));
    ASSERT_FLOAT_EQ(A.getValue(2,2),C.getValue(2,2));
    MatrixTemplate<float> D(2,3);
    ASSERT_THROW(A+=D,std::logic_error);
}

TEST(MatrixTemplate, PlusOperatorTest){
    MatrixTemplate<int> A(2,3);
    A.setValue(1,1,3);
    A.setValue(1,2,5);
    MatrixTemplate<int> B(2,3);
    B.setValue(1,1,1);
    B.setValue(1,2,8);
    MatrixTemplate<int> C=A+B;
    MatrixTemplate<int> D(2,3);
    D.setValue(1,1,4);
    D.setValue(1,2,13);
    ASSERT_FLOAT_EQ(C.getValue(1,1), D.getValue(1,1));
    ASSERT_FLOAT_EQ(C.getValue(1,2), D.getValue(1,2));
    MatrixTemplate <int> E(3,3);
    ASSERT_THROW(A+E, std::logic_error);
}

TEST(MatrixTemplate, MulOperator){
    MatrixTemplate<int> A(2,3);
    A.setValue(1,1,4);
    A.setValue(1,2,5);
    A.setValue(1,3,1);
    A.setValue(2,2,2);
    MatrixTemplate<int> B(2,3);
    ASSERT_THROW(A*B, std::logic_error);
    MatrixTemplate<int> C(3,2);
    C.setValue(1,1,2);
    C.setValue(1,2,1);
    C.setValue(2,1,3);
    C.setValue(3,2,4);
    MatrixTemplate<int> D(2,2);
    D=A*C;
    ASSERT_EQ(D.getValue(1,1), 23);
    ASSERT_EQ(D.getValue(1,2), 8);
    ASSERT_EQ(D.getValue(2,1), 6);
    ASSERT_EQ(D.getValue(2,2), 0);
    C=C*3;
    ASSERT_EQ(C.getValue(1,1),6);
    ASSERT_EQ(C.getValue(1,2),3);
    ASSERT_EQ(C.getValue(2,1),9);
    ASSERT_EQ(C.getValue(3,2),12);
}

TEST(MatrixTemplate, TransposeTest){
    MatrixTemplate<float> A(2,3);
    A.setValue(1,1,4.2);
    A.setValue(1,2,5.3);
    A.setValue(1,3,1.5);
    A.setValue(2,2,2.8);
    MatrixTemplate<float> B(A.transpose());
    ASSERT_FLOAT_EQ(B.getValue(1,1),4.2);
    ASSERT_FLOAT_EQ(B.getValue(2,1),5.3);
    ASSERT_FLOAT_EQ(B.getValue(3,1),1.5);
    ASSERT_FLOAT_EQ(B.getValue(2,2),2.8);
}

TEST(MatrixTemplate, getValueTest){
    MatrixTemplate<int> A(2,2);
    A.setValue(1,1,4);
    A.setValue(1,2,3);
    A.setValue(2,1,1);
    A.setValue(2,2,10);
    ASSERT_EQ(A.getValue(2,1),1);
    ASSERT_THROW(A.getValue(3,1), std::out_of_range);
}

TEST(MatrixTemplate, setValueTest) {
    MatrixTemplate<long int> A(2, 2);
    A.setValue(1, 1, 4);
    A.setValue(1, 2, 3);
    A.setValue(2, 1, 1);
    A.setValue(2, 2, 10);
    ASSERT_THROW(A.setValue(2,3,1),std::out_of_range);
}

TEST(MatrixTemplate, SelectRowTest){
    MatrixTemplate<int> A(2,2);
    A.setValue(1,1,4);
    A.setValue(1,2,3);
    A.setValue(2,1,1);
    A.setValue(2,2,10);
    MatrixTemplate<int> B(A.selectRow(1));
    ASSERT_EQ(B.getValue(1,1),4);
    ASSERT_EQ(B.getValue(1,2),3);
    ASSERT_ANY_THROW(A.selectRow(3));
}

TEST(MatrixTemplate, SelectColumnTest){
    MatrixTemplate<int> A(2,2);
    A.setValue(1,1,4);
    A.setValue(1,2,3);
    A.setValue(2,1,1);
    A.setValue(2,2,10);
    MatrixTemplate<int> B(A.selectColumn(1));
    ASSERT_EQ(B.getValue(1,1),4);
    ASSERT_EQ(B.getValue(2,1),1);
    ASSERT_ANY_THROW(A.selectColumn(3));
}