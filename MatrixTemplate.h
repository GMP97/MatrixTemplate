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

    bool operator!=(const MatrixTemplate& right) const {
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

    MatrixTemplate operator+(const MatrixTemplate &right) const {
        if (rows != right.rows || columns != right.columns)
            throw std::logic_error(
                    "Il numero delle righe e/o delle colonne non corrisponde");
        MatrixTemplate<T> tmpMatrix(rows, columns);
        for (int i = 0; i < right.rows * right.columns; i++)
            tmpMatrix.buffer[i] = buffer[i] + right.buffer[i];
        return tmpMatrix;
    }

    MatrixTemplate &operator+=(const T &right){
        for(int i=0; i<rows*columns;i++)
            buffer[i]+=right;
        return *this;
    }

    MatrixTemplate &operator+(const T &right){
        MatrixTemplate<T> tmpMatrix(rows, columns);
        for (int i = 0; i < rows * columns; i++)
            tmpMatrix.buffer[i] = buffer[i] + right;
        return tmpMatrix;
    }

    MatrixTemplate operator*(const MatrixTemplate &right) const{
        if (columns != right.rows)
            throw std::logic_error(
                    "Il numero di colonne della prima matrice e il numero delle righe della seconda matrice non corrisponde");
        MatrixTemplate<T> tmpMatrix(rows, right.columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < right.columns; j++) {
                tmpMatrix.buffer[i * right.columns + j] = 0;
                for (int h = 0; h < columns; h++)
                    tmpMatrix.buffer[i * right.columns + j] += buffer[i * columns + h] * right.buffer[h * right.columns + j];
            }
        return tmpMatrix;
    }

    MatrixTemplate &operator*(const T &right) const{
        MatrixTemplate<T> tmpMatrix(rows, columns);
        for (int i=0; i<rows*columns;i++)
            tmpMatrix.buffer[i] = buffer[i]*right;
    }

    MatrixTemplate transpose() const {
        MatrixTemplate<T> tmpMatrix(columns, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                tmpMatrix.buffer[tmpMatrix.columns * j + i] = buffer[columns * i + j];
        return tmpMatrix;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << buffer[columns * (i) + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    T getValue(int i, int j) const {
        if (i > rows|| i<1 || j<1  || j > columns)
            throw std::out_of_range("Elemento fuori dal range della matrice");
        return buffer[columns * (i - 1) + j - 1];
    }

    void setValue(int i, int j, const T &value) const {
        if (i > rows || j > columns)
            throw std::out_of_range("Elemento fuori dal range della matrice");
        buffer[columns * (i - 1) + j - 1] = value;
    }

    MatrixTemplate selectRow(int i) {
        if (i > rows || i<1)
            throw std::out_of_range("Riga fuori dal range della matrice");
        MatrixTemplate<T> tmpMatrix(1, columns);
        for (int j = 0; j < columns; j++)
            tmpMatrix.buffer[j] = buffer[columns * (i - 1) + j];
        return tmpMatrix;
    }

    MatrixTemplate selectColumn(int j) {
        if (j > rows || j<1)
            throw std::out_of_range("Colonna fuori dal range della matrice");
        MatrixTemplate<T> tmpMatrix(rows, 1);
        for (int i = 0; i < rows; i++)
            tmpMatrix.buffer[i] = buffer[j - 1 + columns * i];
        return tmpMatrix;
    }

    int getRows() const{
        return rows;
    }

    int getColumns() const{
        return columns;
    }


private:
    int rows, columns;
    T *buffer;
};

#endif //MATRIXTEMPLATE_MATRIXTEMPLATE_H
