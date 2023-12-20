//
// Created by Rajat Mahesh Gupta on 12/8/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paint.h"
#include "features.h"
#include "input.h"
#include "manipulate.h"
#include "file.h"

int main(int argc, char** argv){
    struct matrix_o *matrix = (struct matrix_o*) malloc(sizeof (struct matrix_o));
    if (argc == 1){
        matrix->row = 10;
        matrix->col = 10;
    } else if (argc == 3) {
        if (atoi(argv[1])==0 || atoi(argv[2])==0 || atoi(argv[1]) < 1 || atoi(argv[2]) < 1){
            if (atoi(argv[1])==0){
                printf("The number of rows is not an integer.\n");
            } else if (atoi(argv[2])==0){
                printf("The number of rows is not an integer.\n");
            } else if (atoi(argv[1]) < 1){
                printf("The number of rows is less than 1.\n");
            } else {
                printf("The number of columns is less than 1.\n");
            }

            printf("Making default board of 10 X 10.\n");
            matrix->row = 10;
            matrix->col = 10;
        } else {
            matrix->row = atoi(argv[1]);
            matrix->col = atoi(argv[2]);
        }
    } else {
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
        matrix->row = 10;
        matrix->col = 10;
    }

    matrix->data = create_board(matrix->row, matrix->col);
    print_out(matrix->row, matrix->col, matrix->data);

    bool validInput = false;

    while(1){
        // TODO : Might have to separate the implementation and input validation
        // as a result we would be able to prevent continuous scanf's from reading the input.
        validInput = take_input(matrix); // Conducts the rest of the functionality
        if (validInput){
            print_out(matrix->row, matrix->col, matrix->data);
        }
    }
}
