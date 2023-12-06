#include <stdio.h>
#include <stdlib.h>
#include "mat_multiply.h"

void get_matrix_dimensions_from_user(char* prompt, int* num_rows, int* num_cols){
    /*
    Display the given prompt to the user, then read two integers from the
    user storing the result in num_rows and num_cols
    @prompt: The prompt to show to the user
    @num_rows: the address of where to store the first number entered by the user
    @num_cols: the address of where to store the second number entered by the user
    @returns: nothing
    @modifies: num_rows, num_cols
    */

    printf("%s", prompt);
    scanf("%d %d", num_rows, num_cols);

}

int** make_empty_matrix(int row_dim, int col_dim) {
    /*
    Dynamically create a row_dim X col_dim matrix
    A matrix here is an array of integers
    You do not need to initialize the values of the numbers in
    the matrix, but you can if you want
    @row_dim: the number of rows the matrix should have
    @col_dum: the number of columns the matrix should have
    @returns: a row_dim X col_dim matrix of integers
    @modifies: nothing
    */

    int **newMatrix = (int **)malloc(row_dim * sizeof(int *));

    for (int r = 0; r < row_dim; ++r) {
        newMatrix[r] = (int *)malloc(col_dim * sizeof(int));
    }
    return newMatrix;

}

void fill_matrix_from_user_input(int** matrix, int row_dim, int col_dim) {
    /*
    Fill in the row_dim X col_dim matrix with values entered by the user.
    The user will enter in row_dim rows that each have col_dim elements in it.
    For example if row_dim = 3 and col_dim = 4 the user could enter something like
    11 25 43 45
    10 45 63 17
    -8 25 -9 24

    These values should be stored into matrix
    @matrix: the matrix to be filled in
    @row_dim: the number of rows matrix has
    @col_dum: the number of columns matrix has
    @returns: nothing
    @modifies: matrix
    */

    for (int r = 0; r < row_dim; ++r){
        for (int c = 0; c < col_dim; ++c){
            scanf("%d", &matrix[r][c]);
        }
    }

}

int** matrix_multiply(int** matrix_a, int num_rows_a, int num_cols_a,
											int** matrix_b, int num_rows_b, int num_cols_b,
											int* out_num_rows_c, int* out_num_cols_c) {
    /*
    Multiply matrix_a and matrix_b together, returning the resulting matrix
    Set out_num_rows_c to be the number of rows in the resulting matrix
    Set out_num_cols_c to be the number of cols in the resulting matrix
    @matrix_a: the A in C = A X B
    @num_rows_a: the number of rows in matrix a
    @num_cols_a: the number of columns in matrix a
    @matrix_b: the B in C = A X B
    @num_rows_b: the number of rows in matrix b
    @num_cols_b: the number of columns in matrix b
    @out_num_rows_c: where to store the number of rows of the resulting matrix
    @out_num_cols_c: where to store the number of columns of the resulting matrix
    @returns: matrix_a X matrix_b
    @modifies: out_num_rows_c, out_num_cols_c
    */
    if (num_cols_a == num_rows_b){
        *out_num_rows_c = num_rows_a;
        *out_num_cols_c = num_cols_b;
    }


    int **outMatrix = (int **)malloc(*out_num_rows_c * sizeof(int *));
    for (int i = 0; i < num_rows_a; ++i) {
        outMatrix[i] = (int *)malloc(*out_num_cols_c * sizeof(int));
    }

    for (int r = 0; r < *out_num_rows_c; ++r){
        for (int c = 0; c < *out_num_cols_c; ++c){
            outMatrix[r][c] = 0; // initializes first value to 0.
            for (int pos = 0; pos < num_cols_a; ++pos) {
                outMatrix[r][c] += matrix_a[r][pos] * matrix_b[pos][c];
            }
        }
    }
    return outMatrix;

}

void print_matrix(int** matrix, int row_dim, int col_dim) {
    /*
    Print matrix to the screen
    @matrix: the matrix to be printed
    @row_dim: the number of rows in matrix
    @col_dim: the number of columns in matrix
    @returns: nothing
    @modifies: nothing
    */

    for (int r = 0; r < row_dim; ++r){
        for (int c = 0; c < col_dim; ++c){
            if (c == col_dim-1){
                printf("%d\n", matrix[r][c]);
                continue;
            }
            printf("%d ", matrix[r][c]);
        }
    }
}

void delete_matrix(int ***matrix, int row_dim) {
    /*
    Delete matrix AND set it to NULL.
    @matrix: the address of the matrix to be deleted
    @row_dim: the number of rows in matrix
    @col_dim: the number of columns in matrix
    @returns: nothing
    @modifies: matrix
    */

    for (int i = 0; i < row_dim; ++i){
        free((*matrix)[i]);
        (*matrix)[i] = NULL; // Set each row pointer to NULL
    }
    free(*matrix);
    *matrix = NULL; // Set the array of pointers to NULL
}


void check_matrix_is_null(int** matrix, const char* matrix_name){
    /*
    print whether matrix has been set to NULL or not
    @matrix: the matrix to check if it has been set to NULL
    @matrix_name: the name of the matrix
    */
    if(matrix == NULL){
        printf("%s set to NULL.\n", matrix_name);
    }else{
        printf("%s was NOT set to NULL!\n", matrix_name);
    }
}

int main() {
    int** matrix_a;
    int num_rows_a, num_cols_a;

    int** matrix_b;
    int num_rows_b, num_cols_b;

    int** matrix_c;
    int num_rows_c, num_cols_c;

    get_matrix_dimensions_from_user("Enter the dimensions of matrix A: ", &num_rows_a, &num_cols_a);
    matrix_a = make_empty_matrix(num_rows_a, num_cols_a);
    printf("Enter Matrix A\n");
    fill_matrix_from_user_input(matrix_a, num_rows_a, num_cols_a);

    get_matrix_dimensions_from_user("Enter the dimensions of matrix B: ", &num_rows_b, &num_cols_b);
    matrix_b = make_empty_matrix(num_rows_b, num_cols_b);
    printf("Enter Matrix B\n");
    fill_matrix_from_user_input(matrix_b, num_rows_b, num_cols_b);


    matrix_c = matrix_multiply(matrix_a,  num_rows_a,  num_cols_a,
                               matrix_b,  num_rows_b,  num_cols_b,
                               &num_rows_c, &num_cols_c);

    printf("A * B = \n");
    print_matrix(matrix_c, num_rows_c, num_cols_c);

    delete_matrix(&matrix_a, num_rows_a);
    delete_matrix(&matrix_b, num_rows_b);
    delete_matrix(&matrix_c, num_rows_c);

    check_matrix_is_null(matrix_a, "matrix_a");
    check_matrix_is_null(matrix_b, "matrix_b");
    check_matrix_is_null(matrix_c, "matrix_c");

    return 0;
}


