//
// Created by gmp on 08/03/18.
//

#ifndef MATRIXTEMPLATE_MATRIXTEMPLATE_H
#define MATRIXTEMPLATE_MATRIXTEMPLATE_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cfloat>
#include "UtilsMatrixTemplate.h"

template <typename T>
class MatrixTemplate {
public:
    MatrixTemplate(int r, int c) : rows(r), columns(c){
        if (r<1)
            rows=1;
        if (c<1)
            columns=1;
        buffer = new T[rows * columns];
        for(int i=0;i<rows*columns;i++)
            buffer[i]=0;
    }

    ~MatrixTemplate(){
        delete[] buffer;
    }

    MatrixTemplate(const MatrixTemplate &right){
        rows = right.rows;
        columns = right.columns;
        buffer = new T[rows* columns];
        for(int i=0; i<rows*columns; i++)
            buffer[i]=right.buffer[i];
    }

    MatrixTemplate &operator=(const MatrixTemplate &right){
        rows = right.rows;
        columns = right.columns;
        delete[] buffer;
        buffer = new T[rows* columns];
        for(int i=0; i<rows*columns; i++)
            buffer[i]=right.buffer[i];
        return *this;
    }

    bool operator==(const MatrixTemplate &right)const {
        if(rows!=right.rows)
            return false;
        if(columns!=right.columns)
            return false;
        for(int i=0; i<rows*columns; i++) {
            if (!isEqual(buffer[i], right.buffer[i]))
                return false;
        }
        return true;
     }

    bool operator!=(const MatrixTemplate& right)const {
        return !(*this==right);
    }

    MatrixTemplate &operator+=(MatrixTemplate &right){
        if(rows!=right.rows || columns!=right.columns)
            throw std::logic_error(
                "Il numero delle righe e/o delle colonne non corrisponde");
       for(int i=0;i<rows*columns;i++)
           buffer[i]+=right.buffer[i];
        return *this;
    }

    MatrixTemplate &operator+(MatrixTemplate &left, MatrixTemplate &right){
        if(left.rows!=right.rows || left.columns!=right.columns)
            throw std::logic_error(
                    "Il numero delle righe e/o delle colonne non corrisponde");
        MatrixTemplate tmp(left.rows, left.columns);
        for(int i=0;i<rows*columns;i++)
            tmp.buffer[i]=left.buffer + right.buffer[i];
        return *this;
    }
    

    MatrixTemplate &operator+=(T &right){
        for(int i=0; i<rows*columns;i++)
            buffer[i]+=right;
    }

    MatrixTemplate &operator*(MatrixTemplate &right){

    }
private:
    int rows, columns;
    T *buffer;
};

#endif //MATRIXTEMPLATE_MATRIXTEMPLATE_H
