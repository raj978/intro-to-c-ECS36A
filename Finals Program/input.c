//
// Created by Rajat Mahesh Gupta on 12/12/23.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "features.h"
#include "paint.h"
#include "file.h"
#include "input.h"
#include "manipulate.h"
#include "canvas.h"

/**
 * This is a helper function that is used to check for whether or not a
 * given dimension exists.
 * @param r : number of rows input by the user
 * @param c : number of cols input by the user
 * @param row : x dimension of the canvas
 * @param col : y dimension of the canvas
 * @return true if the dimensions are valid and false otherwise
 */
bool dimensionExists(int r, int c, int row, int col){
    if (r <= row-1 && c <= col-1 && r >= 0 && c >= 0){
        return true;
    } else {
        return false;
    }
}

/**
 * Used to ensure that the start and end points for the draw points are valid coordinates.
 * @param x1 : x coordinate of the start point
 * @param y1 : y coordinate of the start point
 * @param x2 : x coordinate of the second point
 * @param y2 : y coordinate of the second point
 * @param row : num of rows on the canvas.
 * @param col : num of cols on the canvas.
 * @return true if the input is valid and false otherwise
 */
bool drawTest(int x1, int y1, int x2, int y2, int row, int col){
    // the notation is used to denote delta/difference
    int dx = y2 - y1;
    int dy = x2 - x1;

    // checks for the possibility of straight, horizontal and slanting lines.
    // Also ensures that the column, where the point is being trying to added exists
    if (x1 == x2 && y2 == y1){
        return true;
    } else if ((dy == dx || dy == -dx || -dy == dx || x1 == x2 || y1 == y2) && dimensionExists(x1, y1, row, col) && dimensionExists(x2, y2, row, col)){
        // Returns true after the matrix is updated
        return true;
    } else {
        return false;
    }
}

/**
 * This is a helper function that is used to print out the
 * relevant error message depending on the add or delete row
 * command input by the user.
 * @param op : This is used to store the operation.
 */
void add_del_error_reporting(char op){
    if (op == 'a'){
        printf("Improper add command.\n");
    } else {
        printf("Improper delete command.\n");
    }
}

/**
 * This is a helper function that is used to search for whether or not the input file name
 * is valid.
 * @param fileName : this is the string that is input by the user.
 * @return : 1 if the file name is valid and 0 otherwise.
 * The value is returned to a conditional statement that is used for input validation.
 */
int isValidFileName(const char *fileName) {
    int length = strlen(fileName);

    // Check if the length is at least 5 characters (minimum for ".txt")
    if (length < 5) {
        return 0; // Not a valid file name
    }

    // Check if the last four characters are ".txt"
    if (strcmp(fileName + length - 4, ".txt") == 0) {
        return 1; // Valid file name
    }

    return 0; // Not a valid file name

}


bool take_input( matrix_o* matrix){

    printf("Enter your command: ");
    char fChar;
    // takes in the first character to determine the command to implement
    if(scanf(" %c", &fChar) != 1){
        printf("Unrecognized command. Type h for help.\n");
        return false;
    }
    bool validInput = false; // Used by the switch statement below
    int *x1, *x2, *y1, *y2;
    char *axis;
    char* fileName;
    switch (fChar){

        case 'q':
            exit(0); // Used to exit the program

        case 'h':
           print_help();
           return true;


        case 'w':
            x1 = (int*) malloc(sizeof(int));
            y1 = (int*) malloc(sizeof(int));
            x2 = (int*) malloc(sizeof(int));
            y2 = (int*) malloc(sizeof(int));
            // Format : w start_row start_column end_row end_column

            if(scanf(" %d %d %d %d", x1, y1, x2, y2) != 4) {
                printf("Improper draw command.\n");
                return false;
            }
            validInput = drawTest(*x1, *y1, *x2, *y2, matrix->row, matrix->col);

            if (!validInput){
                printf("Improper draw command.\n");
                return validInput; // Prevents the program from continuing and asks the user for input again.
            }
            type_of_line(*x1, *y1, *x2, *y2, matrix);
            free(x1);
            free(x2);
            free(y1);
            free(y2);
            break;

        case 'e':
            // Format : e row col
            x1 = (int *) malloc(sizeof(int));
            y1 = (int*) malloc(sizeof(int));
            if(scanf(" %d %d", x1, y1) != 2) {
                printf("Improper erase command.\n");
                return false;
            }

            validInput = dimensionExists(matrix->row - 1 - *x1, *y1, matrix->row, matrix->col);

            if(!validInput){
                printf("Improper erase command.\n");
                return validInput;
            }

            matrix->data = eraseCell(matrix->row - 1 - *x1, *y1, matrix->data);

            free(x1);
            free(y1);
            break;

        case 'r':
            // format : r row col
            x1 = (int *) malloc(sizeof(int));
            y1 = (int*) malloc(sizeof(int));
            if(scanf(" %d %d", x1, y1) != 2) {
                printf("Improper resize command.\n");
                return false;
            }

            // No change is made if the size of the matrix is not changed
            if (*x1 == matrix->row || *y1 == matrix->col ){
                return true;
            }

            if (*x1 < 1 || *y1 < 1){
                printf("Improper resize command.\n");
                return false;
            }

            *matrix = resizeCanvas(*x1, *y1, matrix);
            free(x1);
            free(y1);
            break;

        case 'a':
        case 'd':
            // format : [a|d] [r|c] row/col
            // Either the value of the row or column will be present
            axis = (char*) malloc(sizeof (char));
            x1 = (int *) malloc(sizeof(int));
            if (scanf(" %c %d", axis, x1) != 2){
                add_del_error_reporting(fChar);
                return false;
            }

            // TO check whether the second letter is r/c
            if (*axis == 'c'){
                if (fChar == 'a'){
                    if (*x1 < 0 || *x1 > matrix->col){
                        add_del_error_reporting(fChar);
                        return false;
                    }
                    matrix->data = addColumn(*x1, matrix->data, matrix->row, &matrix->col);
                } else {
                    if (*x1 < 0 || *x1 >= matrix->col){
                        add_del_error_reporting(fChar);
                        return false;
                    }
                    matrix->data = deleteColumn(*x1, matrix->data, matrix->row, &matrix->col);
                }

            } else if (*axis == 'r'){
                if (fChar == 'a'){
                    if (*x1 < 0 || *x1 > matrix->row){
                        add_del_error_reporting(fChar);
                        return false;
                    }
                    matrix->data = addRow(*x1, matrix->data, &matrix->row, matrix->col);
                } else {
                    if (*x1 < 0 || *x1 >= matrix->row){
                        add_del_error_reporting(fChar);
                        return false;
                    }
                    matrix->data = deleteRow(*x1, matrix->data, &matrix->row, matrix->col);
                }

            } else {
                add_del_error_reporting(fChar);
                return false;
            }
            free(x1);
            free(axis);
            break;

        case 's':
            fileName = (char*) malloc(256 * sizeof (char));
            if (scanf(" %s", fileName) == 0){
                printf("Improper save command or file could not be created.\n");
                return false;
            }

            // Check if the input is a valid file name
            // isValidFileName checks length and whether the name contains .txt
            if (isValidFileName(fileName)) {
                saveToFile(fileName, matrix); // function is used to load the current state of the canvas into fileName
            } else {
                printf("Improper save command or file could not be created.\n");
                return false;
            }

            free(fileName);
            break;

        case 'l':
            fileName = (char*) malloc(sizeof (char));
            if (scanf(" %s", fileName) == 0){
                printf("Improper load command or file could not be opened.\n");
                return false;
            }

            // Check if the input is a valid file name
            if (isValidFileName(fileName)) {
                *matrix = loadFromFile(fileName);
            } else {
                printf("Improper load command or file could not be opened.\n");
                return false;
            }

            
            free(fileName);
            break;

        default:
            printf("Unrecognized command. Type h for help.\n");
            return false;

    }
    return true;
}
