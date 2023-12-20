//
// Created by Rajat Mahesh Gupta on 12/14/23.
//
#include "paint.h"
#include "manipulate.h"


// TODO : create a function to manage intersections
// TODO : This function will be called, each time any of the parent function experience a point
// wherein the current cell already contains a sign that is not a *.

// TODO : create a function that takes in a row col pair and determines whether there is a char there except for a *
int empty(int x, int y, char sign, char** matrix){
    if (matrix[x][y] == '*'){
        return 1; // empty space in the canvas returns true
    } else {
        if (matrix[x][y] == '+'){
            return 0;
        } else if (matrix[x][y] == sign){
            return 0;
        } else {
            matrix[x][y] = '+';
            return 0;
        }
    }
}

/**
 * Helper function to draw a horizontal line from a start point to end point.
 * @param x1 : x ordinate of start point
 * @param y1 :
 * @param x2
 * @param y2
 * @param matrix
 * @return
 */
char** drawHorizontal(int x1, int y1, int y2, char** matrix, int row){
    int swapY;
    // swaps the y values in case the start point is further from the end point.
    if (y1 > y2){
        swapY = y1;
        y1 = y2;
        y2 = swapY;
    }

    for (int i = y1; i <= y2; ++i){
        if (empty(row - 1 - x1, i,'-', matrix)) {
            matrix[row - 1 - x1 ][i] = '-';
        }
    }

    return matrix;
}

// TODO : Function for vertical lines
// Should be able to manage low-high and high-low
char** drawVertical(int x1, int x2, int y1, char** matrix, int row){
    int swapX;
    // swaps the x values in case the start point is further from the end point.
    if (x1 > x2){
        swapX = x1;
        x1 = x2;
        x2 = swapX;
    }

    for (int i = x1; i <= x2; ++i){
        if (empty(row - 1 - i, y1,'|', matrix)){
            matrix[row - 1 - i][y1] = '|';
        }
    }

    return matrix;

}

// TODO : Function to create slanting lines
// Should be able to manage 4 axis slants of both pairs.
char** drawSlant(int x1, int y1, int x2, int y2, char** matrix, int row){
    int dy = y2 - y1;
    int dx = x2 - x1;
    if ( dy == dx ){
        // The Line has a positive slant
        if (x1 < x2){ // The start point is x1
            for (int i = 0; i <= x2-x1; ++i){
                if (empty(row - 1 - (i + x1), y1 + i,'/', matrix)){
                    matrix[row - 1 - (i + x1)][y1 + i] = '/';
                }
            }
        } else { // The start point is x2
            for (int i = 0; i <= x1-x2; ++i){
                if (empty(row - 1 - (i + x2), y2 + i,'/', matrix)){
                    matrix[row - 1 - (i + x2)][y2 + i] = '/';
                }
            }
        }
    } else {
        // the line has a negative slant
        if (x1 < x2){ // The start point is x1,y1
            for (int i = 0; i <= x2-x1; ++i){
                if (empty(row - 1 - (i + x1), y1 - i,'\\', matrix)){
                    matrix[row - 1 - (i+x1)][y1 - i] = '\\';
                }
            }
        } else { // The start point is x2, y2
            for (int i = 0; i <= x1-x2; ++i){
                if (empty(row - 1 - (x1 - i), y1 + i,'\\', matrix)){
                    matrix[row - 1 - (x1 - i)][y1 + i] = '\\';
                }
            }
        }
    }

    return matrix;
}

void type_of_line(int x1, int y1, int x2, int y2, matrix_o* matrix){
    // TODO : The function decides the type of line to draw assuming the input is valid.
    // TODO : It then proceeds to call a function to replace the set of points with the relevant character.
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (x1 == x2 && y2 != y1){
        // If the line is horizontal
        matrix->data = drawHorizontal(x1, y1, y2, matrix->data, matrix->row);
    } else if (y2 == y1 && x2 != x1){
        matrix->data = drawVertical(x1, x2, y1, matrix->data, matrix->row);
    } else if ((dx==dy || -dx == dy || dx == -dy) && (x1 != x2 && y2 != y1)){
        matrix->data = drawSlant(x1, y1, x2, y2, matrix->data, matrix->row);
    } else if (x1 == x2 && y2 == y1){
        if (empty(matrix->row - 1 - x1, y1,'-', matrix->data)){
            matrix->data[matrix->row - 1 - x1][y1] = '-';
        }
    }
}


