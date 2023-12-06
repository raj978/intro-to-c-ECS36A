//
// Created by Rajat Mahesh Gupta on 11/16/23.
//
#include <stdbool.h>

#ifndef CONNECTN_WIN_H
#define CONNECTN_WIN_H
    bool win(int row, int col, int numToWin, char*** board);
    void vertical(int row, int col, int numToWin, char*** board, bool *isVertical, char *winner);
    void horizontal(int row, int col, int numToWin, char*** board, bool* isHorizontal, char* winner);
    void slant_negative(int row, int col, int numToWin, bool* is_slant, char*** board, char* winner );
    void slant_positive(int row, int col, int numToWin, bool* is_slant, char*** board, char* winner );
#endif //CONNECTN_WIN_H
