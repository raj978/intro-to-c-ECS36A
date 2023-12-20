
#ifndef FINALS_PROGRAM_FEATURES_H
#define FINALS_PROGRAM_FEATURES_H
#include "paint.h"
    void print_out(int row, int col, char** matrix);
    char** create_board(int row, int col);
    char** eraseCell(int x, int y, char** matrix);
    void print_help();
    matrix_o resizeCanvas(int newRows, int newCols, matrix_o* matrix);
#endif //FINALS_PROGRAM_FEATURES_H
