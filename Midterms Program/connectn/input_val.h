#include <stdbool.h>
#ifndef CONNECTN_INPUT_VAL_H
#define CONNECTN_INPUT_VAL_H
    bool verify_input(int row, int col, int num_to_win);
    bool col_is_empty(int row, int checkCol, char*** board);
    bool board_full(int row, int col, char*** board);
    bool verify_col(int col, int limit);
#endif //CONNECTN_INPUT_VAL_H
