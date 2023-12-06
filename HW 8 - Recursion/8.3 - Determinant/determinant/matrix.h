//
// Created by Rajat Mahesh Gupta on 12/1/23.
//

#ifndef C_SCHOOL_DETERMINANT_H
#define C_SCHOOL_DETERMINANT_H
    // Define a struct for a matrix
    typedef struct {
        int rows;
        int cols;
        double** data;
    } Matrix;
    #include <stdio.h>
    Matrix createMatrix(int rows, int cols);
    void freeMatrix(Matrix* mat);
    Matrix readMatrix(FILE* file);
#endif //C_SCHOOL_DETERMINANT_H
