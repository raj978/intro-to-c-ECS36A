
#ifndef FINALS_PROGRAM_MANIPULATE_H
#define FINALS_PROGRAM_MANIPULATE_H
    void type_of_line(int x1, int y1, int x2, int y2, matrix_o *matrix);
    char** drawHorizontal(int x1, int y1, int y2, char** matrix, int row);
    char** drawVertical(int x1, int x2, int y1, char** matrix, int row);
    char** drawSlant(int x1, int y1, int x2, int y2, char** matrix, int row);
    int empty(int x, int y, char sign, char** matrix);
#endif //FINALS_PROGRAM_MANIPULATE_H
