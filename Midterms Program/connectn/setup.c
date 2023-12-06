#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setup.h"
/**
 * This function is used to setup the empty board.
 * It is only called at the start of the program.
 * @param row : user input for number of rows.
 * @param col  : user input for number of columns.
 * @param board : Array of character pointers which stores the pieces of the connectn game.
 */
char*** initialize_board(int row, int col){
    // Dynamically allocate memory for the 2D array
    char ***board = (char ***)malloc(row * sizeof(char **));
    for (int i = 0; i < row; ++i) {
        board[i] = (char **)malloc(col * sizeof(char*));
    }
    char* star = "*";
    char* space = " ";
    int reverse_row = 0;
    for (int r = row-1; r >= 0; --r){
        for (int c = 0; c < col; ++c){
            if (r == 0 && c == 0){
                board[reverse_row][c] = space;
            } else if (r == 0){
                char buffer[10];  // Adjust the buffer size as needed
                sprintf(buffer, "%d", c - 1);
                board[reverse_row][c] = strdup(buffer);
            } else if(c == 0){
                char buffer[10];  // Adjust the buffer size as needed
                sprintf(buffer, "%d", r - 1);
                board[reverse_row][c] = strdup(buffer);
            } else {
                board[reverse_row][c] = star;
            }
        }
        reverse_row ++;
    }
    return board;
}

/**
 * Used to print the board when requested. Doesn't return any vale.
 * @param rows : user input for number of rows.
 * @param cols : user input for number of columns.
 * @param board : Array of character pointers which stores the pieces of the connectn game.
 */
void print_board(int rows, int cols, char ***board){
    for (int r = 0; r < rows; ++r){
        for (int c  = 0; c < cols; ++c){
            if (c != cols-1){
                printf("%c ", *board[r][c]);
            } else {
                printf("%c", *board[r][c]);
            }

        }
        printf("\n");
    }
}

/**
 * Function returns the bard and updates the pieces on it, after
 * obtaining the input for the selected column represented by y.
 * @param Player : It is used to store whether to append an X or O.
 * @param y : Stores the value of the input column from the user.
 * @param row : the number of rows as input by the user at the start of the program.
 * @param board : Array of character pointers which stores the pieces of the connectn game.
 * @return It returns the value of board.
 */
char*** update_board(char Player, int y, int row, char*** board){
    for (int r = row-2; r >= 0 ; --r){
        if(board[r][y][0] == '*'){
            if (Player == 'A'){
                char buffer[10];  // Adjust the buffer size as needed
                sprintf(buffer, "%s", "X");
                board[r][y] = strdup(buffer);
            } else {
                char buffer[10];  // Adjust the buffer size as needed
                sprintf(buffer, "%s", "O");
                board[r][y] = strdup(buffer);
            }
            break;
        }
    }
    return board;
}
