/**
 * Created by Rajat Mahesh Gupta on 11/2/23.
 * This is a program that is trying to add 2 matrices A and B, by first providing the
 * number of rows and columns of Matrix A and B, which is followed by the addition of
 * each of the values adding the respective rows and columns.
*/

#include <stdio.h>

/**
 * This function is used to input the matrices input by the user.
 * It is a void function and hence doesn't return a statement but stores the user input into a matrix.
 * @param matrixNum is used to produce the correct prompt for the user to input matrices A and B.
 * @param rows is used to store the number of rows in the matrix.
 * @param cols is used to store the number of columns in the matrix.
 * @param matrix is used to store the value of the input data into the target matrix.
 */
void GetMatrix(char matrixNum, int rows, int cols, int matrix[rows][cols]) {

    // Code below guides user input
    if (matrixNum == 'A') {
        printf("Enter Matrix A\n");
    } else {
        printf("Enter Matrix B\n");
    }

    // Code below stores matrix input values from the user.
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            scanf("%d", &matrix[r][c]);
        }
    }
}

/**
 * AddMatrix() function is used to take as input the variable below and add them.
 * It is a void function and hence doesn't return a value.
 * It stores the added value of matrix A and B into the array matrix.
 * @param rows stores the input number of rows.
 * @param cols stores the input number of columns.
 * @param matrixOne is the first matrix from which the values need to be added.
 * @param matrixTwo is the second matrix from which the values need to be added.
 * @param matrix is the matrix used to store the values from the resulting addition of Matrix One and Two.
 */

void AddMatrix(int rows, int cols, int matrixOne[rows][cols], int matrixTwo[rows][cols], int matrix[rows][cols]){
    for (int r = 0; r < rows; ++r){
        for (int c = 0; c < cols; ++c){
            matrix[r][c] = matrixOne[r][c] + matrixTwo[r][c];
        }
    }
}

/**
 * OutputMatrix() function is used to output the value of the matrix from the addition operation.
 * It is a void function and hence doesn't return a value.
 * @param rows stores the input number of rows.
 * @param cols stores the input number of columns.
 * @param matrixAdded is the matrix used to store the values from the resulting addition of Matrix One and Two.
 */

void OutputMatrix(int rows, int cols, int matrixAdded[rows][cols]){
    for (int r = 0; r < rows; ++r){
        for (int c = 0; c < cols; ++c){
            printf("%d", matrixAdded[r][c]);
        }
    }
}

int main(void) {
    // These are the declared variables to store rows, columns and guide user input.
    int rows;
    int cols;
    char inputMatrix;

    // Below are the statements to allow user input on number of rows and columns.
    printf("Please enter the number of rows: ");
    scanf(" %d", &rows);

    printf("Please enter the number of columns: ");
    scanf(" %d", &cols);

    // These are the declared variable names for the arrays to store user input
    int matrixOne[rows][cols];
    int matrixTwo[rows][cols];
    int matrixAdded[rows][cols];

    inputMatrix = 'A'; // Used to indicate output to guide user to enter first matrix.
    GetMatrix(inputMatrix, rows, cols,matrixOne);

    inputMatrix = 'B'; // Used to indicate output to guide user to enter second matrix.
    GetMatrix(inputMatrix, rows, cols, matrixTwo);

    AddMatrix(rows, cols, matrixOne, matrixTwo,matrixAdded);

    printf("A + B =\n");
    OutputMatrix(rows, cols, matrixAdded);

    return 0;
}
