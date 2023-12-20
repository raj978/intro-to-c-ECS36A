//
// Created by Rajat Mahesh Gupta on 12/12/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "features.h"
#include "paint.h"

/**
 * This function sets up the board with 'empty' value
 * @param row
 * @param col
 * @return
 */
char** create_board(int row, int col){
    char** matrix = (char**) malloc(sizeof (char*)* row);
    for (int i = 0; i < row; ++i){
        matrix[i] = (char*) malloc(sizeof (char) * col);
        for (int j = 0; j < col; ++j){
            matrix[i][j] = '*';
        }
    }

    return matrix;
}

/**
 * This function is used to print the contents of the canvas.
 * @param row
 * @param col
 * @param matrix
 */
void print_out(int row, int col, char** matrix){
    for (int i = 0; i <= row; ++i){

        // Printing out the first few characters for the index of the canvas
        if (i != row){
            printf("%d ", row-1 - i);
        } else {
            printf("  ");
        }

        // Printing out the rest of the board
        for (int j = 0; j < col; ++j){

            // Printing out the contents of the index or the contents of the matrix
            if (i != row){

                // Printing the space except for the last column
                if (j != col-1){
                    printf("%c ", matrix[i][j]); // prints the contents of the matrix
                } else {
                    printf("%c\n", matrix[i][j]); // prints the contents of the matrix
                }

            } else {
                // Printing the space except for the last column
                if (j != col-1){
                    printf("%d ", j); // Printing out the index for the columns on the canvas
                } else {
                    printf("%d\n", j); // Printing out the index for the columns on the canvas
                }
            }

        }

    }
}

/**
 * This function is used by the take input function below to print the commands for h input.
 */
void print_help(){
    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}

char** eraseCell(int x, int y, char** matrix){
    matrix[x][y] = '*';
    return matrix;
}

// Function to resize the canvas
matrix_o resizeCanvas(int newRows, int newCols, matrix_o* matrix) {
    matrix_o newMatrix;
    newMatrix.row = newRows;
    newMatrix.col = newCols;

    // Allocate memory for the new matrix
    newMatrix.data = (char**)malloc(newRows * sizeof(char*));
    for (int i = 0; i < newRows; ++i) {
        newMatrix.data[i] = (char*)malloc(newCols * sizeof(char));
    }

    // Initialize the new matrix with empty spaces
    for (int i = 0; i < newRows; ++i) {
        for (int j = 0; j < newCols; ++j) {
            newMatrix.data[i][j] = '*';
        }
    }

    // Copy the existing content to the new matrix
    for (int i = 0; i < matrix->row && i < newRows; ++i) {
        for (int j = 0; j < matrix->col && j < newCols; ++j) {
            newMatrix.data[i][j] = matrix->data[i][j];
        }
    }

    // Free the memory of the old matrix
    for (int i = 0; i < matrix->row; ++i) {
        free(matrix->data[i]);
    }
    free(matrix->data);

    return newMatrix;
}