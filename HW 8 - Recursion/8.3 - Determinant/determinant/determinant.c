//
// Created by Rajat Mahesh Gupta on 12/1/23.
//
#include <stdio.h>
#include "matrix.h"


// Function to calculate the findDeterminant of a matrix
double findDeterminant(Matrix mat) {
    /*if (mat.rows != mat.cols || mat.rows == 0) {
        fprintf(stderr, "Error: Invalid matrix dimensions for findDeterminant calculation\n");
        exit(EXIT_FAILURE);
    }*/

    if (mat.rows == 1) {
        return mat.data[0][0];
    }

    if (mat.rows == 2) {
        return mat.data[0][0] * mat.data[1][1] - mat.data[0][1] * mat.data[1][0];
    }

    double det = 0.0;

    for (int i = 0; i < mat.cols; ++i) {
        Matrix submatrix = createMatrix(mat.rows - 1, mat.cols - 1);

        for (int j = 1; j < mat.rows; ++j) {
            int k = 0;
            for (int l = 0; l < mat.cols; ++l) {
                if (l != i) {
                    submatrix.data[j - 1][k++] = mat.data[j][l];
                }
            }
        }

        double cofactor = (i % 2 == 0 ? 1 : -1) * mat.data[0][i];
        det += cofactor * findDeterminant(submatrix);

        freeMatrix(&submatrix);
    }

    return det;
}

int main(int argc, char** argv) {

    FILE* file = fopen(argv[1], "r");

    Matrix mat = readMatrix(file);
    fclose(file);

    double det = findDeterminant(mat);

    printf("The determinant is %.2lf.\n", det);

    freeMatrix(&mat);
}
