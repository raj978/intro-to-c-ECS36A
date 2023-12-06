/**
 * Created by Rajat Mahesh Gupta on 11/15/23.
 * This program is used to play a game of connect, where the number of
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include "setup.h"
#include "input_val.h"
#include "play.h"

int main(int argc, char* argv[]){

    /**
     * Checks input argument length
     * Terminates program if there are not 3 inputs.
     */
    if (argc != 4){
        if (argc > 4){
            printf("Too many arguments entered\n");
        } else if(argc < 4){
            printf("Not enough arguments entered\n");
        }
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        return 0;
    }

    // Used to verify the value obtained from command line input
    if (!verify_input(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]))){
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        return 0;
    }

    // Allocating memory for variables
    int* row =(int *) malloc(sizeof(int));;
    int* col = (int *) malloc(sizeof (int));;
    int* connect_len = (int *) malloc(sizeof(int));

    // Initializing the variables
    *row = atoi(argv[1])+1;
    *col = atoi(argv[2])+1;
    *connect_len = atoi(argv[3]);

    // Setting up the board
    char ***board = initialize_board(*row, *col);
    print_board(*row, *col, board);

    // Playing the game
    play_game(*row, *col, *connect_len, board);

    // Freeing the memory allocated to the variables at the start of the program
    for (int i = 0; i < *row-1; ++i) {
        free(board[i]);  // Free the array of strings
    }
    free(board);  // Free the array of pointers

    free(row);
    free(col);
    free(connect_len);

    return 0;
}

