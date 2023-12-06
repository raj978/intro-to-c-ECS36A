#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Used to count the number of words in the input file.
 * @param fp : is the name of the variable storing the file pointer.
 * @param count : is the number of words that have been counted.
 * @return is count which is the number of words with an integer datatype.
 */
int getCount(FILE* fp, int* count) {
    char *c = (char*) malloc(sizeof (char));
    int t_count = 0; // count to check for consecutive characters in a word
    while ((*c = fgetc(fp)) != EOF) {
        if (!isspace(*c)) {
            t_count++;
        } else {
            if (t_count > 0) {
                (*count)++;
                t_count = 0;
            }
        }
    }
    if (t_count > 0) {
        /* counts if any leftover words were present not included due to the character
        reaching EOF. */
        (*count)++;
    }

    return *count;
}

/**
 * Used to get the file from user input.
 * The function doesn't input anything but just changes the file pointer - fp.
 * @param fileName : is the second element from command line input containing the file name.
 * @param fp : is the name of the variable storing the file pointer.
 * @param count : is probably just 0, to show 0 words were read in case of no
 * non-whitespace characters in the file.
 */
void getFile(char* fileName, FILE** fp, int* count) {
    *fp = fopen(fileName, "r");

    // Check if the file is opened successfully
    if (*fp == NULL) {
        printf("Error opening the file.\n");
        exit(1); // Return an error code or handle the error appropriately
    }
}

int main(int argc, char* argv[]) {
    FILE* fp;
    int* count = (int*) malloc(sizeof (int));
    *count = 0;
    getFile(argv[1], &fp, count); // used to get input from the user text file.

    // Displays the total number of words in the file.
    printf("There are %d word(s).\n", getCount(fp, count));

    // Close the file
    fclose(fp);

    return 0;
}
