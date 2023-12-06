#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "play.h"
#include "win.h"
#include "setup.h"
#include "input_val.h"

/**
 * A helper function called by get_column to check whether or not
 * the column from user input is valid.
 * @param input : character string from user input
 * @param selected_col : Integer version of the input column used by the program.
 * @param row : integer rows from user
 * @param col : integer columns from user
 * @param board : array of character pointers containing the connectn pieces.
 * @return true if the check is satisfied and false if not.
 */

bool checkCondition(char* input, int row, int col, char*** board) {

//    int len = strlen(input);
//
//    // Remove the newline character if it exists
//    if (len > 0 && input[len - 1] == '\n') {
//        input[len - 1] = '\0';
//    }
    input[strcspn(input, "\n")] = '\0';
    if (!isdigit((unsigned char)(*input))) {
        return true; // Not a digit
    }

    int selected_col = atoi(input) + 1;

    if (!verify_col(selected_col, col) || !col_is_empty(row, selected_col, board)) {
        return true; // Invalid column or column is not empty
    }

    return false; // Condition is met
}


/**
 * Function verifies whether or not input column value is valid.
 * @param row : input value of the size of the rows from user input.
 * @param col : input value of column size from user input.
 * @param board : array of character pointers containing the connectn pieces.
 * @return the value of the selected column in integer.
 */
int get_column(int row, int col, char*** board){
    int selected_col = 0;
    char input[100];

    do {
        printf("Enter a column between 0 and %d to play in: ", (col-2));
        fgets(input, sizeof(input), stdin);

        if (checkCondition(input, row, col, board)) {
            continue; // Continue the loop if the condition is not met
        }

        // Update selected_col after taking input
        selected_col = atoi(input) + 1;

    } while (checkCondition(input, row, col, board));

    return selected_col;
}

/**
 * Controls the call of the helper functions and controls the general flow of the program.
 * This includes core features of taking user input, updating and displaying the board,
 *
 * @param row : Integer value for the number of rows in the board from user input.
 * @param col: Integer value for the number of columns in the board from user input.
 * @param connect_len : Integer value for the number of rows in the board from user input.
 * @param board : array of character pointers to store pieces of the connectn game.
 */
void play_game(int row, int col, int connect_len, char*** board){
    int turn = 0;
    int target ;
    bool won, board_is_empty;
    do{
        if (turn % 2 == 0){
            target = get_column(row, col, board);
            board = update_board('A', target, row, board);
        } else {
            target = get_column(row, col, board);
            board = update_board('B', target, row, board);
        }
        turn++;
        print_board(row, col, board);
        won = win(row, col, connect_len, board); // prints output, if there is a winner
        if (won){
            return;
        }
        board_is_empty = !board_full(row, col, board); // false if board is full
    }while (board_is_empty);
    if (board_full(row, col, board)){
        printf("Tie game!\n");
    }
}