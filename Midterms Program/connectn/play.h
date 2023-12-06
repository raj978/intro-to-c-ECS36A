//
// Created by Rajat Mahesh Gupta on 11/16/23.
//

#ifndef CONNECTN_PLAY_H
#define CONNECTN_PLAY_H
    int get_column(int row, int col, char*** board);
    void play_game(int row, int col, int connect_len, char*** board);
    bool checkCondition(char* input, int row, int col, char*** board);
#endif //CONNECTN_PLAY_H
