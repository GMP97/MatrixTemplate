//
// Created by gmp on 10/03/18.
//

#ifndef MATRIXTEMPLATE_UTILSMATRIXTEMPLATE_H
#define MATRIXTEMPLATE_UTILSMATRIXTEMPLATE_H


#include <cmath>
#include <cfloat>



template<typename T>
bool isEqual(const T&left, const T&right) {
    return left==right;
}

template<>
bool isEqual<float>(const float&left,const float&right) {
    return fabsf(left - right) <= FLT_EPSILON;
}

template<>
bool isEqual<double>(const double&left,const double&right) {
    return fabs(left - right) <= FLT_EPSILON;
}

#endif //MATRIXTEMPLATE_UTILSMATRIXTEMPLATE_H
