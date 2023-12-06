#include <stdlib.h>
#include <stdio.h>

#include "read_lines.h"


/**
 * This is a void function which is assigning more lines to the variable lines.
 * It also added more columns to the current line so that more characters can be appended in the following steps.
 * @param lines : This is the variable that is being assigned more memory.
 * @param num_lines : This is the additional number of lines being assigned to the variable lines.
 */
void moreRowMemory(char*** lines, int** num_lines) {
    // Allocate more memory if needed
    if (**num_lines % 1 == 0) {
        *lines = (char**)realloc(*lines, (**num_lines + 1) * sizeof(char*));
        (*lines)[**num_lines] = (char*)malloc(1 * sizeof(char));
    }
}

/**
 * This is a void function is used to assign more memory to each row.
 * By adding 10 more to each column, the program is able to dynamically assign more memory to the variable input.
 * @param lines : This is the variable that is being assigned more memory.
 * @param col : This is the existing memory allocated to line, which is being incremented by 10.
 */
void moreColMemory(char*** lines, int** num_lines, int** col) {
    // Allocate more memory if needed
    if (**col % 1 == 0) {
        (*lines)[**num_lines] = (char*)realloc((*lines)[**num_lines], (**col + 1) * sizeof(char));
    }
}


void read_lines(FILE* fp, char*** lines, int* num_lines) {
    /*
        read all the lines in fp into lines and set num_lines to be the total number of lines in the file.
        @fp: a file pointer opened in read mode
        @lines: a pointer indicating where the lines should be placed. If there are no lines in a fill, lines
                will be set to NULL
        @num_lines: a pointer to the number of lines. set to the number of lines contained within lines
        @modifies: lines, num_lines
    */

    char* c = (char*)malloc(sizeof(char));
    int* row = (int*) malloc(sizeof (int));
    int* col = (int*) malloc(sizeof (int));

    *row = 0;
    *col = 0;

    *num_lines = 0;

    // Allocate memory for the first line
    *lines = (char**)malloc(sizeof(char*));
    (*lines)[*row] = (char*)malloc(sizeof(char));

    while ((*c = fgetc(fp)) != EOF) {
        if (*c == '\n') {
            moreColMemory(lines, &num_lines, &col);
            (*lines)[*row][*col] = '\n';
            (*col)++;
            // Null-terminate the current line
            moreColMemory(lines, &num_lines, &col);
            (*lines)[*row][*col] = '\0';
            (*num_lines)++;



            // Move to the next line
            (*row)++;
            *col = 0;
            moreRowMemory(lines, &num_lines);

        } else {
            moreColMemory(lines, &num_lines, &col);

            // Store the character in the current line
            (*lines)[*row][*col] = *c;
            (*col)++;
        }
    }
    if (*col > 0 ){
        moreColMemory(lines, &num_lines, &col);
        (*lines)[*row][*col] = '\n';
        (*col)++;
        // Null-terminate the current line
        moreColMemory(lines, &num_lines, &col);
        (*lines)[*row][*col] = '\0';
        (*num_lines)++;
        // Move to the next line



    } else if (*row > 0 && *col == 0) {
        // Null-terminate the last line
        moreColMemory(lines, &num_lines, &col);
        (*lines)[*row][*col] = '\n';
        (*col)++;
        moreColMemory(lines, &num_lines, &col);
        (*lines)[*row][*col] = '\0';

    } else {
        moreColMemory(lines, &num_lines, &col);
        (*lines)[*row][*col] = '\0';
    }


    // Free the temporary character buffer
    free(c);
    free(row);
    free(col);
}

