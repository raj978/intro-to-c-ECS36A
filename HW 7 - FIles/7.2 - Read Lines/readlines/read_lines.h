#ifndef READ_LINES_H
	#define READ_LINES_H
	#include <stdio.h>
	void read_lines(FILE* fp, char*** lines, int* num_lines);
    void moreRowMemory(char*** lines, int** num_lines);
    void moreColMemory(char*** lines, int** row, int** col);
#endif
