//
// Created by Rajat Mahesh Gupta on 11/16/23.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "win.h"

// Function to check along the vertical dimension of the board
void vertical(int row, int col, int numToWin, char*** board, bool *isVertical, char *winner){
    char temp;
    int count;
    for (int c = 1; c < col; ++c){
        count = 0;
        for (int r = row-2; r > 0; --r){
            temp = board[r][c][0];
            if(board[r-1][c][0] == temp && temp != '*'){
                count ++;
                if (count == numToWin-1){
                    if (temp == 'X'){
                        *winner = 'A';
                    } else {
                        *winner = 'B';
                    }
                    *isVertical = true;
                    return;
                }
            } else{
                count = 0;
            }
            //if (count == (numToWin-1) || (count == row-2 && row == col)){
        }
    }
}

// Function to check along the horizontal dimension of the board
void horizontal(int row, int col, int numToWin, char*** board, bool* isHorizontal, char* winner){
    char temp;
    int count;
    for (int r = row-2; r >= 0; --r){
        count = 0;
        for (int c = 1; c < col-1; ++c){
            temp = board[r][c][0];
            if (board[r][c+1][0] == temp && temp != '*'){
                count++;
                //if (count == numToWin-1 || (count == col-2 && col == row)){
                if (count == numToWin-1){
                    if (temp == 'X'){
                        *winner = 'A';
                    } else {
                        *winner = 'B';
                    }
                    *isHorizontal = true;
                    return;
                }
            } else{
                count = 0;
            }

        }
    }
}

// Function to check for a win along the negative slant
void slant_negative(int row, int col, int numToWin, bool* is_slant, char*** board, char* winner) {
    char temp;
    int count;

    // Check along the negative slant
    for (int r = row - 2; r >= 0; --r) {
        for (int c = 1; c < col; ++c) {
            count = 0;
            temp = board[r][c][0];

            // Check diagonal elements along the negative slant
            for (int i = 0; i < numToWin && r + i < row && c + i < col ; ++i) {
                if (board[r + i][c + i][0] == temp && temp != '*') {
                    count++;
                    //if (count == numToWin || (count == col-1 && col == row)){
                    if (count == numToWin){
                        if (temp == 'X'){
                            *winner = 'A';
                        } else {
                            *winner = 'B';
                        }
                        *is_slant = true;
                        return;
                    }
                } else {
                    break;
                }
            }
        }
    }
}

// Function to check for a win along the positive slant
void slant_positive(int row, int col, int numToWin, bool* is_slant, char*** board, char* winner) {
    char temp;
    int count;

    // Check along the positive slant
    for (int r = row - 2; r >= 0; --r) {
        for (int c = col - 1; c > 0; --c) {
            count = 0;
            temp = board[r][c][0];

            // Check diagonal elements along the positive slant
            for (int i = 0; i < numToWin && r + i < row && c - i > 0; ++i) {
                if (board[r + i][c - i][0] == temp && temp != '*') {
                    count++;

                    //if (count == numToWin || (count == col-1 && col == row)){
                    if (count == numToWin){
                        if (temp == 'X'){
                            *winner = 'A';
                        } else {
                            *winner = 'B';
                        }
                        *is_slant = true;
                        return;
                    }
                } else {
                    break;
                }
            }
        }
    }
}

/**
 * Used as a yes no function to indicate whether or not there
 * is a single winner.
 * @param row : Number of rows in the board
 * @param col : Number of columns in the board
 * @param numToWin : Number of connections needed to win
 * @param board : The array od character pointers containing the board pieces.
 * @return If there is a winner, it returns true else it returns false.
 */
bool win(int row, int col, int numToWin, char*** board){
    char* winner = (char*) malloc(sizeof(char));
    bool* is_vertical = (bool *) malloc(sizeof (bool));
    bool* is_horizontal = (bool *) malloc(sizeof (bool));
    bool* is_slant = (bool *) malloc(sizeof (bool));
    vertical(row, col, numToWin, board, is_vertical, winner);
    horizontal(row, col, numToWin, board, is_horizontal, winner);
    slant_negative(row, col, numToWin, is_slant, board, winner);
    slant_positive(row, col, numToWin,is_slant, board, winner);
    free(is_horizontal);
    free(is_vertical);
    free(is_slant);
    if  (winner != NULL &&(winner[0] == 'A' || winner[0] == 'B')) {
        if (winner[0] == 'A') {
            printf("Player 1 Won!\n");
        } else {
            printf("Player 2 Won!\n");
        }
        free(winner);
        return true;
    } else {
        return false;
    }
}