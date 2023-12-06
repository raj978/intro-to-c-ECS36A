#include "input_val.h"

/**
 * Used to verify the number of command line arguments.
 * @param row : Input from user
 * @param col : Input from user
 * @param num_to_win : Input from user
 * @return boolean value of yes / no.
 */
bool verify_input(int row, int col, int num_to_win){
    if (row > 0 && col > 0 && num_to_win > 0){
        return true;
    } else {
        return false;
    }
}

/**
 * Used to make sure the column to place the piece in exists.
 * @param col : Value of column which the piece is being appended to.
 * @param limit : Value of the number of columns from user input.
 * @return true or false depending on whether the column exits and is not full
 */
bool verify_col(int col, int limit){
    if (col > 0 && col < limit){
        return true;
    } else {
        return false;
    }
}

/**
 * Function to check whether or not a given column has an empty space
 * @param row
 * @param checkCol
 * @param board
 * @return
 */
bool col_is_empty(int row, int checkCol, char*** board){
    for (int i = row-2; i >= 0; --i){
        if (board[i][checkCol][0] == '*') {
            return true;
        }
    }
    return false;
}

/**
 * Function to check whether or not the board is full.
 * @param row : user input for number of rows.
 * @param col : user input for number of columns.
 * @param board
 * @return false if the board has empty spaces.
 */
bool board_full(int row, int col, char ***board){
    for (int r = 0; r < row-2; ++r){
        for (int c = 1; c < col; ++c){
            if (board[r][c][0] == '*') {
                return false;
            }
        }
    }
    return true;
}
