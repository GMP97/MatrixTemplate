//
// Created by gmp on 10/03/18.
//

#include "gtest/gtest.h"

#include "../MatrixTemplate.h"

TEST(MatrixTemplate, MatrixTemplate_DefaultConstructor_Test) {
    MatrixTemplate<int> A(3,5);
    ASSERT_EQ(3, A.getRows());
    ASSERT_EQ(5, A.getColumns());
    ASSERT_EQ(A.getValue(1,1),0);
}

TEST(MatrixTemplate, MatrixTemplate_MatrixTemplate_CopyConst_Test){
    MatrixTemplate<float> A(2,4);
    A.setValue(1,1, 1.2);
    A.setValue(1,2, 2.3);
    A.setValue(1,3, 3);
    A.setValue(2,1, 3.5);
    MatrixTemplate<float> B(A);
    ASSERT_TRUE(A==B);
}

