//
// Created by Rajat Mahesh Gupta on 12/13/23.
//
#include <stdio.h>
#include "paint.h"
#include "file.h"
#include <stdlib.h>

void saveToFile(const char* filename, matrix_o* matrix) {
    FILE* file = fopen(filename, "w");

    // Write the number of rows and columns to the file
    fprintf(file, "%d %d\n", matrix->row, matrix->col);

    // Write the canvas representation to the file
    for (int i = matrix->row - 1; i >= 0; i--) {
        for (int j = 0; j < matrix->col; j++) {
            fprintf(file, "%c ", matrix->data[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

matrix_o loadFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    matrix_o matrix;

    // Read the number of rows and columns from the file
    if (fscanf(file, "%d %d", &matrix.row, &matrix.col) != 2) {
        fprintf(stderr, "Error reading file format\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the canvas
    matrix.data = malloc(matrix.row * sizeof(char*));
    for (int i = 0; i < matrix.row; i++) {
        matrix.data[i] = malloc(matrix.col * sizeof(char));
    }

    // Read the canvas representation from the file
    for (int i = matrix.row - 1; i >= 0; i--) {
        for (int j = 0; j < matrix.col; j++) {
            if (fscanf(file, " %c", &matrix.data[i][j]) != 1) {
                fprintf(stderr, "Error reading canvas data\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    return matrix;
}