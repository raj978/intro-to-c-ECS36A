//
// Created by Rajat Mahesh Gupta on 12/1/23.
//

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>


// Function to allocate memory for a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;

    mat.data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; ++i) {
        mat.data[i] = (double*)malloc(cols * sizeof(double));
    }

    return mat;
}

// Function to free memory used by a matrix
void freeMatrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; ++i) {
        free(mat->data[i]);
    }
    free(mat->data);
}

// Function to read a matrix from a file
Matrix readMatrix(FILE* file) {
    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    Matrix mat = createMatrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(file, "%lf", &mat.data[i][j]);
        }
    }

    return mat;
}


