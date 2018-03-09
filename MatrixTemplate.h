//
// Created by gmp on 08/03/18.
//

#ifndef MATRIXTEMPLATE_MATRIXTEMPLATE_H
#define MATRIXTEMPLATE_MATRIXTEMPLATE_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cfloat>

template <typename T>
class MatrixTemplate {
public:
    MatrixTemplate(int r, int c) : rows(r), columns(c){
        if (r<1)
            T rows=1;
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

    bool operator==(const MatrixTemplate &right){
        if(rows!=right.rows)
            return false;
        if(columns!=right.columns)
            return false;
        for(int i=0; i<rows*columns; i++)//da modificare
            if (buffer[i]!=right.buffer)
                return false;
        return true;
     }

    bool operator!=(const MatrixTemplate &right){
        if(rows==right.rows)
            return false;
        if(columns==right.columns)
            return false;
        for(int i=0; i<rows*columns; i++)
            if (buffer[i]==right.buffer)//da modificare
                return false;
        return true;
    }

    MatrixTemplate &operator+=(MatrixTemplate &right){
        if(rows!=right.rows || columns!=right.columns)
            throw std::logic_error(
                "Il numero delle righe e/o delle colonne non corrisponde");
       for(int i=0;i<rows*columns;i++)
           buffer[i]+=right.buffer[i];
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
