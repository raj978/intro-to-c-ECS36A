//
// Created by Rajat Mahesh Gupta on 12/15/23.
//
#include "canvas.h"
#include <stdlib.h>

char** addRow(int position, char** matrix, int* row, int col) {
    // Create a new matrix with an additional row
    char **newMatrix = (char **) malloc((*row + 1) * sizeof(char *));
    if (position == *row){
        // Add a new row at the specified position
        newMatrix[0] = (char *) malloc(col * sizeof(char));
        for (int j = 0; j < col; ++j) {
            newMatrix[0][j] = '*';
        }
        // Copy existing rows before the specified position
        for (int i = 1 ; i <= *row; ++i) {
            newMatrix[i] = (char *) malloc(col * sizeof(char));
            for (int j = 0; j < col; ++j) {
                newMatrix[i][j] = matrix[i-1][j];
            }
        }
    } else {
        // Copy existing rows before the specified position
        for (int i = 0 ; i < *row - position; ++i) {
            newMatrix[i] = (char *) malloc(col * sizeof(char));
            for (int j = 0; j < col; ++j) {
                newMatrix[i][j] = matrix[i][j];
            }
        }

        // Add a new row at the specified position
        newMatrix[*row - position] = (char *) malloc(col * sizeof(char));
        for (int j = 0; j < col; ++j) {
            newMatrix[*row - position][j] = '*';
        }

        // Copy existing rows after the specified position
        for (int i = *row - position + 1; i < *row + 1; ++i) {
            newMatrix[i] = (char *) malloc(col * sizeof(char));
            for (int j = 0; j < col; ++j) {
                newMatrix[i][j] = matrix[i - 1][j];
            }
        }
    }


    // Free the memory of the old matrix
    for (int i = 0; i < *row; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    // Update the row count
    (*row)++;

    return newMatrix;
}

char** addColumn(int position, char** matrix, int row, int *col) {
    // Create a new matrix with an additional column
    char** newMatrix = (char**)malloc(row * sizeof(char*));

    // Allocate memory for each row in the new matrix
    for (int i = 0; i < row; ++i) {
        newMatrix[i] = (char*)malloc((*col + 1) * sizeof(char));
    }

    // Copy existing elements before the specified position in each row
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < position; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    // Add a new column at the specified position in each row
    for (int i = 0; i < row; ++i) {
        newMatrix[i][position] = '*'; // Initialize with '*' or any desired character
    }

    // Copy existing elements after the specified position in each row
    for (int i = 0; i < row; ++i) {
        for (int j = position; j < *col; ++j) {
            newMatrix[i][j + 1] = matrix[i][j];
        }
    }

    // Free the memory of the old matrix
    for (int i = 0; i < row; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    // Update the col count
    (*col)++;

    return newMatrix;
}


char** deleteRow(int position, char** matrix, int* row, int col) {
    // Create a new matrix with one less row
    char** newMatrix = (char**)malloc((*row - 1) * sizeof(char*));

    // Allocate memory for each row in the new matrix
    if (position == *row-1){
        // Allocates and assigns memory to the rows after the position
        for (int i = 0 ; i < *row - 1 ; ++i) {
            newMatrix[i] = (char*)malloc(col * sizeof(char));
            // Copy existing elements in each row, excluding the row to be deleted
            for (int j = 0; j < col; ++j) {
                newMatrix[i][j] = matrix[i+1][j];
            }
        }
    } else {
        // Allocates and assigns memory to the rows before position is reached
        for (int i = 0 ; i < *row - 1 - position; ++i) {
            newMatrix[i] = (char*)malloc(col * sizeof(char));
            // Copy existing elements in each row, excluding the row to be deleted
            for (int j = 0; j < col; ++j) {
                newMatrix[i][j] = matrix[i][j];
            }
        }
        // Skip the position and continue copying in values after the position if its
        // less than the total number of rows.
        for (int i = *row - 1 - position; i < *row - 1 ; ++i){
            newMatrix[i] = (char*)malloc(col * sizeof(char));
            // Copy the rest of the remaining rows after position
            for (int j = 0; j < col; ++j){
                newMatrix[i][j] = matrix[i+1][j];
            }
        }
    }

    // Free the memory of the old matrix
    for (int i = 0; i < *row; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    // Update the row count
    (*row)--;

    return newMatrix;
}

char** deleteColumn(int position, char** matrix, int row, int *col) {
    if (position < 0 || position >= *col) {
        // Invalid position
        return matrix;
    }

    // Create a new matrix with one less column
    char** newMatrix = (char**)malloc(row * sizeof(char*));

    // Allocate memory for each row in the new matrix
    for (int i = 0; i < row; ++i) {
        newMatrix[i] = (char*)malloc((*col - 1) * sizeof(char));

        // Copy existing elements before the specified position in each row
        for (int j = 0, k = 0; j < *col; ++j) {
            if (j != position) {
                newMatrix[i][k] = matrix[i][j];
                k++;
            }
        }
    }

    // Free the memory of the old matrix
    for (int i = 0; i < row; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    // Update the column count
    (*col)--;

    return newMatrix;
}